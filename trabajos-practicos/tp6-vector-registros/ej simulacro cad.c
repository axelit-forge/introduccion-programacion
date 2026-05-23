#include <stdio.h>
#include <string.h>
#define TAMV 20
#define TAMC 30
typedef char tcad[TAMC];
typedef struct{
	int nrolinea;
	tcad linea;
	tcad LINEA;
	int cpalabras;
}reglin;		
typedef reglin vectreg[TAMV];

void LeeCad(tcad);
int ContPalabras(tcad);
reglin IngReg(void);
void IngVectOrd(vectreg,int*);
void InsertarPalabra(vectreg);
void ConcatenaPalab(tcad,tcad);
void ActualizarPalabra(vectreg,int);
void Pinsertar(vectreg,int*);
void InsertaOrdenado(vectreg,int*, int,tcad);
void MuestraLineas(vectreg,int);
int menu();
int main() {
	vectreg PARRAFO;
	int N,opc;
	IngVectOrd(PARRAFO,&N);
	do{
		opc=menu();
		switch(opc){
			case 1:
				InsertarPalabra(PARRAFO); break;
			case 2:
				Pinsertar(PARRAFO,&N); break;
			case 3:
				MuestraLineas(PARRAFO,N); break;
			default: 
				printf("Opcion no valida\n");
				break;
		}
	}while(opc!=4);
	return 0;
}
reglin IngReg(void){
	reglin AUX;
	printf("Ingrese numero de linea: "); scanf("%d",&AUX.nrolinea);
	printf("Ingrese linea: "); LeeCad(AUX.linea);
	strcpy(AUX.LINEA,AUX.linea);
	strupr(AUX.LINEA);
	AUX.cpalabras=ContPalabras(AUX.linea);
	return AUX;
}
void LeeCad(tcad A){
	fflush(stdin);
	int j;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF&&c!='\n'&&j<TAMC-1){
		A[j]=c;
		j++;
		c=getchar();
	}
	A[j]='\0';
	while(c!=EOF&&c!='\n'){
		c=getchar();
	}
}
int ContPalabras(tcad A){
	int cont,i;
	i=0,cont=1;
	while(A[i]!='\0'){
		if(A[i]==' '&&A[i-1]!=' ')
			cont++;
		i++;
	}
return cont;
}
void IngVectOrd(vectreg A,int*N){
	int i,j;
	printf("Ingrese tamanio de la lista: "); scanf("%d",N);
	A[1]=IngReg();
	for(i=2;i<=*N;i++){
		A[0]=IngReg();
		j=i-1;
		while(A[0].nrolinea<A[j].nrolinea){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=A[0];
	}
}
void InsertarPalabra(vectreg A){
	int nrolin;
	tcad aux;
	printf("En que linea desea insertar la palabra?: "); scanf("%d",&nrolin);
	printf("Ingrese palabra a insertar: "), LeeCad(aux);
	ConcatenaPalab(A[nrolin].linea,aux);
	ActualizarPalabra(A,nrolin);
}
void ConcatenaPalab(tcad A,tcad B){
	strcat(A," ");
	strcat(A,B);
}
void ActualizarPalabra(vectreg A,int pos){
	strcpy(A[pos].LINEA,A[pos].linea);
	strupr(A[pos].LINEA);
	A[pos].cpalabras++;
}
void Pinsertar(vectreg A,int* N){
	tcad nvalinea;
	int pos;
	printf("Ingrese la linea que desee insertar: "); LeeCad(nvalinea);
	printf("Ingrese la posicion de la linea: "); scanf("%d",&pos);
	InsertaOrdenado(A,N,pos,nvalinea);
}
void InsertaOrdenado(vectreg A,int* N, int pos,tcad elem){
	int i;
	for(i=*N;i>=pos;i--){
		A[i+1]=A[i];
		A[i+1].nrolinea++;
	}
	strcpy(A[pos].linea,elem);
	*N=*N+1;
}
void MuestraLineas(vectreg A,int N){
	int i;
	for(i=1;i<=N;i++){
		printf("%s\n",A[i].linea); 
	}
}
int menu(){
	int opc;
	printf("\n---------MENU---------\n");
	printf("\n(1) AGREGAR PALABRA A UNA LINEA");
	printf("\n(2) INSERTAR NUEVA LINEA");
	printf("\n(3) MOSTRAR TODAS LAS LINEAS");
	printf("\n(4) SALIR");
	printf("\nOpcion ingresada: ");
	scanf("%d",&opc);
	return opc;
}
