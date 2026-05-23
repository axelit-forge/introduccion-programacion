#include <stdio.h>
#include <stdlib.h>
	
typedef struct nodo{
	int data;
	struct nodo* next;
}TNodo;

typedef TNodo* tLista;

tLista Inicializar ();
void CargarUno(tLista*);
void EliminaUno(tLista*);
void VerificaBingo(tLista);
short PosibleBingo(tLista);
short Vacio(tLista);
void MostrarLista(tLista);

short Menu();

int main(void) {
	tLista Numeros;
	tLista Aux;
	short opt=-1;
	
	Numeros=Inicializar();
	
	do{
		opt=Menu();
		switch(opt){
		case 1: 
			CargarUno(&Numeros); 
			break;
		case 2: 
			if(!Vacio(Numeros)) EliminaUno(&Numeros);
			else printf("\n La lista está vacia");
			break;
		case 3:
			if(PosibleBingo(Numeros))
				VerificaBingo(Numeros);
			break;
		case 0: 
			while (Numeros != NULL) {
				Aux = Numeros;
				Numeros = (Numeros)->next;
				free(Aux);
			}
			printf("\n Saliendo del programa..."); break;
		case 4: MostrarLista(Numeros); break;
		default: printf("\n Opcion invalida"); break;
		}
		
	} while(opt!=0);
	
	return 0;
}

tLista Inicializar (){
	tLista Nvo;
	Nvo=NULL;
	return Nvo;
}
int CargaDato(){
	int A;
	printf("\nIngrese el numero siguiente del bingo: ");
	scanf("%d", &A);
	return A;
}
	
tLista CreaPuntero(){
	tLista Aux;
	Aux=(TNodo*) malloc (sizeof(TNodo));
	Aux->data= CargaDato();
	Aux->next= NULL;
	return Aux;
}
void AgregaOrdenado(tLista* Pri, tLista Nvo){
	tLista Aux=NULL, Ant=NULL;
	if(*Pri!=NULL){
		Aux=*Pri;
		while(Aux!=NULL && Aux->data<Nvo->data){
			Ant=Aux;
			Aux= Aux->next;
		}
		if(Ant==NULL){
			Nvo->next=*Pri;
			*Pri=Nvo;
		}
		else
		{
			Ant->next=Nvo;
			Nvo->next=Aux;
		}
	}
	else
	   *Pri=Nvo;
}
	
void CargarUno(tLista* Pri){
	tLista Nvo;
	Nvo=CreaPuntero();
	AgregaOrdenado(Pri, Nvo);
}
	
void Eliminar(tLista * Pri, int busc){
	tLista Aux, Ant;
	Ant=NULL;
	Aux= *Pri;
	while(Aux!=NULL && Aux->data!=busc){
		Ant=Aux;
		Aux= Aux->next;
	}
	if (Aux == NULL) {
		printf("\nNo se encontró el elemento %d en la lista.\n", busc);
		
	}
	else{
		if (Ant == NULL) 
			*Pri = Aux->next;
		else 
			Ant->next = Aux->next;
		free(Aux);
	}
}
	
void EliminaUno(tLista* Pri){
	int solicitado;
	
	printf("\n Ingrese el numero a eliminar");
	scanf("%d", &solicitado);
	Eliminar(Pri, solicitado);	
}

int BuscaNum(tLista Pri, int num){
	while(Pri!=NULL && Pri->data!=num)
		Pri= Pri->next;
	if(Pri!=NULL)
		return 1;
	else
		return 0;
	
}
	
void VerificaBingo(tLista Pri){
	int Num;
	int i, b;
	i=1; b=0;
	
	while(i<=15 && b==0){
		printf("\n Ingrese el sig numero: ");
		scanf("%d", &Num);
		
		if((BuscaNum(Pri, Num))!=1)
			b=1;
		i++;
	}
	if(b==0)
		printf("\n HUBO UN GANADOR");
	else
		printf("\n un numero no salió todavia");
}

short PosibleBingo(tLista Pri) {
	int count = 0;
	while (Pri != NULL) {
		count++;
		Pri = Pri->next;
	}
	return count >= 15; 
}
short Vacio(tLista Pri){
	return (Pri==NULL);
}

short Menu() {
	short op;
	printf("\nOpciones:\n");
	printf("1. Agregar un número al bingo.\n");
	printf("2. Eliminar un número del bingo.\n");
	printf("3. Verificar si hay un ganador.\n");
	printf("4. Mostrar la lista.\n");
	printf("0. Salir.\n");
	printf("Elija: ");
	scanf("%hd", &op);
	return op;
}
	
void MostrarLista(tLista Pri) {
	printf("\nLista actual: ");
	while (Pri != NULL) {
		printf("%d -> ", Pri->data);
		Pri = Pri->next;
	}
	printf("NULL\n");
}	
