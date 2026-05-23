#include "TAD_Complex.h"
#include <stdio.h>

short Menu();
void CargaDatos(RComplex*, RComplex*);

int main (){
	RComplex A, B, C;
	short opt;
	
	CargaDatos(&A, &B);
	
	do{
		opt=Menu();
		switch(opt){
		case 1: 
			C=SumComplex(A, B);
			ShowComplex(C);
			break;
		case 2:
			C=RestComplex(A, B);
			ShowComplex(C);
			break;
		case 3: 
			C=ProdComplex(A, B);
			ShowComplex(C);
			break;
		case 4: 
			C= CocComplex(A, B);
			ShowComplex(C);
			break;
		case 5:
			CargaDatos(&A, &B);
			break;
		case 6:
			printf("A: "); ShowComplex(A);
			printf("\nB: "); ShowComplex(B);
			break;
		case 0:
			printf("\n Saliendo...");
			break;
		default: printf("\n OPCION INVALIDA");
		}
		
	} while(opt!=0);
	
	return 0;
}
	
short Menu(){
	
	short op;
	
	printf("\n===============================================");
	printf("\nBienvenido/a! Elija lo que quiere realizar");
	printf("\n[1] La suma A+B");	
	printf("\n[2] La resta A-B");
	printf("\n[3] El producto A*B");
	printf("\n[4] El cociente A/B");	
	printf("\n[5] Cambiar los valores de A y B");
	printf("\n[6] Mostrar los valores de A y B actuales ");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("===============================================\n");
	
	return op;
	
	
}
void CargaDatos(RComplex* A, RComplex* B){
	
	printf("Cargue los numeros: ");
	printf("\nA: "); *A= InComplex();
	printf("\nB: "); *B= InComplex();
	
}
