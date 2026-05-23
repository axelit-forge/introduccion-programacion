#include "TAD_Lista.h"


tLista Inicializar(){
	tLista Nvo;
	Nvo=NULL;
	return Nvo;
}
tLista CargaUno(Song N){
	tLista Nvo;
	Nvo=(tLista)malloc(sizeof(tNodo));
	Nvo->Data=N;
	Nvo->Next=NULL;
	
	return Nvo;
}
	
int ListaVacia(tLista Head) {
	if (Head == NULL)
		return 1;
	return 0;
}	
	
int Verif(int bus, tLista Head){									/*privada*/
	
	while (Head != NULL && CmpCodig(Head->Data, bus) != 0) {
		Head = Head->Next;
	}
	if(Head == NULL)
		return 1;
	return 0;
}	

int ObtenerCodigo() {										/*privada*/
	int CodigAux;
	printf("\n Ingrese el codigo: ");
	scanf("%d", &CodigAux);
	return CodigAux;
}

void AgregaOrdenado(tLista* Head, tLista Nvo){
	tLista Ant, Aux;
	
	if(*Head!=NULL){
		
		Ant=NULL;
		Aux=*Head;
		
		while(Aux!=NULL && (CmpCanciones(Nvo->Data, Aux->Data) == 1)) {
			Ant=Aux;
			Aux= Aux->Next;
		}
		if(Ant==NULL){
			Nvo->Next= Aux;
			*Head= Nvo;
		}
		else{
			Nvo->Next=Aux;
			Ant->Next=Nvo;
		}
	}
	else
	   *Head=Nvo;
}

void AgregarUno(tLista* Head) {
	int CodigAux;
	Song Aux;
	tLista Nvo;
	
	CodigAux = ObtenerCodigo();
	
	if (Verif(CodigAux, *Head)) {
		Aux = CargaCancion(CodigAux); 
		Nvo = CargaUno(Aux);  
		AgregaOrdenado(Head, Nvo);  
	} 
	else
		printf("\n El código estaba repetido");
	
}
	
tLista CargarLista(int n) {
	int i;
	tLista Pri=NULL;
	
	for (i = 1; i <= n; i++) 
		AgregarUno(&Pri); 
	return Pri;
}
void MostrarLista(tLista Head){
	printf("\n--------------------------------");
	printf("\n Lista de canciones: \n");
	while (Head != NULL ) {
		MostrarCancion(Head->Data);
		Head = Head->Next;
	}
	
}
	
int Porcentaje(int Total, int Muestra){
	
	return Muestra*100/Total;
}

int ContarTotal(tLista Pri){
	if(Pri!=NULL)
		return 1 + ContarTotal(Pri->Next);
	else
		return 0;
	
}
	
int ContarGenre(tLista Pri, int Genero){
	if(Pri!=NULL){
		if(CmpGenre(Pri->Data, Genero)==1)
			return 1+ContarGenre(Pri->Next, Genero);
		return ContarGenre(Pri->Next, Genero);
		}
	else
	   return 0;
}
	
void ControladorGeneros(tLista Pri, int total){
	int i, c;
	for(i=1; i<=5; i++){
		c=ContarGenre(Pri, i);
		MostrarGenero(i);
		printf(": %%%d", c*100/total);
	}
}
	
	
void MostrarFrec(tLista Head){
	int Total;

	Total=ContarTotal(Head);
	
	ControladorGeneros(Head, Total);
	printf("\n");
}

void MostrarCondicionado(tLista Head, int Campo){
	TCad Buscado;
	tLista Aux;
	printf("\n Ingrese la palabra: "); ScanCad(Buscado);
	
	Aux=Head;
	
	while (Aux != NULL ) {
		if(CmpCampoCad(Aux->Data, Buscado, Campo)==0)
			MostrarCancion(Aux->Data);
		Aux = Aux->Next;
	}
}

	
void FreeLista(tLista* Head) {
	tLista Aux;
	
	while (*Head != NULL) {
		Aux = *Head;          
		*Head = (*Head)->Next; 
		free(Aux);             
	}
	
	*Head = NULL;
}	




