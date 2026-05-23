#include <stdio.h>
#include <string.h>
#define tamano 30

typedef char Word [tamano];
typedef Word VectorCadena [tamano];

short menu();
void cargarLista(VectorCadena, int*);
void mostrarLista(VectorCadena, int);
void mismaVocal(VectorCadena, int);
void ordenarBurbuja(VectorCadena, int);
void BinariaCadena(VectorCadena, int);


int main() {
	VectorCadena A;
	int N;
	short opt;
	
	cargarLista(A, &N);
	ordenarBurbuja(A, N);
	
	
	do{ 
		opt=menu();	
		fflush(stdin);
		switch (opt) {
		case 1 :
			mismaVocal(A, N);			
			break;
		case 2 :	
			BinariaCadena(A, N);
			break;
				
		case 3 :
			
			mostrarLista(A, N);
			break;
			
		case 0:
			break;
			
		default: printf("INVALIDO");
		}
	}while(opt!=0);
	
	printf ("\n\n\tSALIR PROGRAMA");
	
	
	return 0;
}

short menu () {
	
	short op;
	
	printf("\n===============================================");
	printf("\nBienvenido! Elija lo que quiere realizar");
	printf("\n[1] Ver cuantas ciudades están escritas con solo una misma vocal");	
	printf("\n[2] Encontrar una ciudad y su posicion en la lista");
	printf("\n[3] Mostrar toda la lista");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("\n===============================================\n");
	
	return op;
}


void LeeCad (Word A, int tam){
	int j=0; char c;
	c=getchar();
	
	while(c!=EOF && c!= '\n' && j<tam){
		A[j]=c;
		j++;
		c=getchar();
	}
	A[j]= '\0';
	while(c!=EOF && c!='\n')
		c= getchar();
}
	
	
short menu();
void cargarLista(VectorCadena A, int* N){
	int i, tam=tamano;
	printf("Ingrese la cantidad de ciudades de la lista: "); scanf("%d", N);
	fflush(stdin);
	
	for(i=1; i<= *N; i++){
		printf("Ingrese una ciudad: ");
		LeeCad( A[i], tam);
	}
}
void mostrarLista(VectorCadena A, int N){
	int i;
	printf("\n");
	for(i=1; i<=N; i++){
		printf("Ciudad %d: ", i);
		puts(A[i]);
	}
	
}
	
void controler( char N, char* vocal, int* b){
	
	if(N=='a'|| N=='e' ||N=='i'|| N=='o' ||N=='u'){
		if(*b==0){
			*vocal= N;
			*b=1;
		}
		else
			if(N!=*vocal) *b=-1;
	}
}
	
	
void mismaVocal(VectorCadena A, int N){
	int i, j, b, cont=0;
	char vocal;
	
	for(i=1; i<=N; i++){
		j=0;
		b=0;
		while(A[i][j]!='\0'){
			controler(A[i][j], &vocal, &b);
			j++;
		}
		if(b==1)
			cont++;
	}
	
	printf("\nCumplen %d palabras", cont);
	
}
void ordenarBurbuja(VectorCadena A, int N){
	int i, j;
	Word Aux;
	
	for(i=2; i<=N; i++){
		for(j=N; j>=i; j--){
			if(strcmp(A[j], A[j-1])<0)
			{
				strcpy(Aux, A[j]);
				strcpy(A[j], A[j-1]);
				strcpy(A[j-1], Aux);
			}
		}
	}
	
}
	
int Binaria(VectorCadena A, int N, Word Busq){
	int Ini, Fin, Med;
	Ini=1; Fin=N; Med= (Ini+Fin)/2;
	
	while(Ini<=Fin && strcmp(A[Med], Busq) != 0)
	{
		if(strcmp(A[Med], Busq)>0)
			Fin=Med-1;
		else
			Ini=Med+1;
		Med= (Ini+Fin)/2;
	}
	if(Ini>Fin) return -1;
	else
		return Med;
}
	
	
void BinariaCadena(VectorCadena A, int N){
	Word Busq;
	int b;
	printf("\nIngrese la ciudad a buscar: ");
	LeeCad(Busq, 30);
	
	b=Binaria(A, N, Busq);
	if(b==-1) printf("No se encontro");
	else printf("está en la posiscion %d", b);
}
