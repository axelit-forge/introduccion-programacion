#include <stdio.h>
#include <stdlib.h>

#define tamano 30

typedef char group [tamano];

typedef struct{
	int cantidad;
	char name;
	group letras;
}conjunct;






void inicializacion( conjunct*, conjunct*);
void mostrarStruct(conjunct);
short menu();
void ingresarUnElemento(conjunct*);
short menuAB();
void UnionAB (conjunct, conjunct);
void InterseccionAB (conjunct, conjunct);
void RestaConjuntos (conjunct, conjunct);
	
int main() {
	
	conjunct A;
	conjunct B;
	short opt, opcionAB;
	
	inicializacion (&A, &B);
	
	do{ 
	opt=menu();	
	
	switch (opt) {
	case 1 :
		opcionAB=menuAB();
		if(opcionAB==1)
			ingresarUnElemento(&A);
		else
			ingresarUnElemento(&B);
		
		break;
	case 2 :	
		opcionAB=menuAB();
		if(opcionAB==1)
			mostrarStruct(A);
		else
			mostrarStruct(B);;
		
		break;
		
	case 3 :
		
		UnionAB(A,B);
		
		break;
		
	case 4: 
		
		InterseccionAB(A,B);
		
		break;
		
	case 5:
		
		RestaConjuntos(A,B);
		
		break;
		
	case 6:
		
		RestaConjuntos(B,A);
		
		break;
		
	case 7:
		system ("cls");
		break;
		
	case 0:
		break;
		
	default: printf("INVALIDO");
	}
	}while(opt!=0);

	printf ("\n\n\tSALIR PROGRAMA");
	
	mostrarStruct(A);
	mostrarStruct(B);
	
	return 0;
}

void inicializacion( conjunct*A, conjunct*B){
	
	A->name='A';
	B->name='B';
	A->cantidad=0;
	B->cantidad=0;
}

short menu () {
	
	short op;
	
	printf("\n===============================================");
	printf("\nBienvenido! Elija lo que quiere realizar");
	printf("\n[1] Agregar un elemento a uno de los conjuntos");	
	printf("\n[2] Mostrar uno de los conjuntos");
	printf("\n[3] Mostrar la UNION de los conjuntos");
	printf("\n[4] Mostrar la INTERSECCION de los conjuntos");
	printf("\n[5] Mostrar A-B");
	printf("\n[6] Mostrar B-A");
	printf("\n[7] Si desea borrar la pantalla");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("\n===============================================\n");
	
	return op;
}
short menuAB(){
	short b;
	char opcion;
	printf("\n¿A que conjunto desea acceder?");
	printf("\n Ingrese el nombre del conjunto A o B: ");
	fflush(stdin);

	do{ 
		
	if(b==0) printf("Intente denuevo: ");
	scanf("%c", &opcion);
	fflush(stdin);
	
	if(opcion=='A')
		b=1;
	else
		if(opcion == 'B')
			b=2;
		else
			b=0;
	
	
	}while (opcion!= 'A' && opcion!='B');
	
	
	return b;
}

int busquedaSecuencial (conjunct X, char elemento){
	int i=1;
	
	while (i<=X.cantidad && X.letras[i] != elemento)
		i++;
	if (i>X.cantidad)
		return 1;
	else
		return 0;
}	
	
void ingresarUnElemento(conjunct* X){
	char Elemento;
	int N;

	fflush(stdin);
	printf("\nIngrese el elemento que quiere insertar: ");
	scanf("%c", &Elemento);
	if(busquedaSecuencial(*X, Elemento)){
		N=X->cantidad;
		N++;
		X->letras[N]= Elemento;
		X->cantidad=N;
	}
	else printf("ERROR: EL ELEMENTO YA ESTABA\n");
}
	
void mostrarStruct(conjunct X){
	int i;
	
	printf("\n Nombre: %c", X.name);
	printf("\n Cantidad de letras; %d", X.cantidad);
	
	printf("\n Conjunto: { ");
	
	for(i=1; i<= X.cantidad; i++){
		printf("%c, ", X.letras[i]);
	}
	printf("}");
	
}

void UnionAB (conjunct A, conjunct B){
	int elemento;
	int i;
	
	printf("\n UNION AB: { ");
	
	for(i=1; i<= A.cantidad; i++){
		printf("%c, ", A.letras[i]);
	}
	
	for(i=1; i<= B.cantidad; i++){
		elemento=B.letras[i];
		if(busquedaSecuencial(A, elemento))
			printf("%c, ", B.letras[i]);
	}
	
	printf("}");
	
}	
	
void InterseccionAB (conjunct A, conjunct B){
	int elemento;
	int i;
	
	printf("\n INTERSECCION AB: { ");
	
	
	for(i=1; i<= B.cantidad; i++){
		elemento=B.letras[i];
		if(!busquedaSecuencial(A, elemento))
			printf("%c, ", B.letras[i]);
	}
	
	printf("}");
	
}

void RestaConjuntos (conjunct X, conjunct Y){
	int elemento;
	int i;
	
	printf("\n RESTA PEDIDA: { ");
	
	
	for(i=1; i<= X.cantidad; i++){
		elemento=X.letras[i];
		if(busquedaSecuencial(Y, elemento))
			printf("%c, ", X.letras[i]);
	}
	
	printf("}");
	
}
