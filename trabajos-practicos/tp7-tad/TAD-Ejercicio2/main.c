#include "TAD_Conjunct.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

short Menu();

int main (void){
	TConjunto A, B, C;
	short opt, AoB;
	char X;
	srand(time(NULL));
	A=GenConjunto();
	B=GenConjunto();
	
	do{
		opt=Menu();
		switch(opt){
		case 1: 
			printf("\n Ingrese el elemento: "); scanf("%c", &X); 
			printf("\n Agregar a: A [1] / B [2]"); scanf("%hd", &AoB);
			if(AoB==1)
				AgregarElem(&A, X);
			else
				AgregarElem(&B, X);
			break;
		case 2:
			C=Union(A, B);
			ShowConjunto(C);
			break;
		case 3: 
			C=Interseccion(A, B);
			ShowConjunto(C);
			break;
		case 4: 
			printf("\n Mostrar: A-B [1] / B-A [2]"); scanf("%hd", &AoB);
			if(AoB==1)
				C= Resta(A, B);
			else
				C= Resta(B, A);
			ShowConjunto(C);
			break;
		case 5:
			C= DifSimetrica(A, B);
			ShowConjunto(C);
			break;
		case 6:
			A=GenConjunto();
			B=GenConjunto();
			break;
		case 7:
			printf("\n Mostrar: A [1] / B [2]"); scanf("%hd", &AoB);
			
			if(AoB==1){
				printf("A: "); ShowConjunto(A);
			}
			else{
				printf("B: "); ShowConjunto(B);
			}
			break;
			
		case 8: 
			printf("\n Mostrar: A [1] / B [2]"); scanf("%hd", &AoB);
			
			if(AoB==1)
				printf("\n|A|= %d", Cardinal(A));
			else
				printf("\n|B|= %d", Cardinal(B));
			break;
		case 9: 
			if(ContieneA(A, B))
				printf("\nA está contenido en B");
			if(ContieneA(B,A))
				printf("\nB está contenido en A");
		break;
		
		case 10: 
			printf("\n Ingrese el elemento: "); scanf("%c", &X);
			printf("\n Pertenece a: A [1] / B [2]"); scanf("%hd", &AoB);
		if(AoB==1){
			if(Pertenece(A, X))
				printf("\nPertenece");
			else
				printf("\n No Pertenece");
		}
		else{
			if(Pertenece(B, X))
			printf("\nPertenece");
			else
				printf("\n No Pertenece");
		}
		break;
		
		case 11: system("cls"); break;
		
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
	printf("\n[1] Agregar un elemento a algun conjunto");
	printf("\n[2] Hacer y mostrar la Union");	
	printf("\n[3] Hacer y mostrar la Interseccion");
	printf("\n[4] Hacer y mostrar la Resta");
	printf("\n[5] Hacer y mostrar la diferencia Simetrica");	
	printf("\n[6] Volver a generar los conjuntos");
	printf("\n[7] Mostrar los conjuntos ");
	printf("\n[8] Cardinal de un conjunto ");
	printf("\n[9] Calculo de contención ");
	printf("\n[10] Calculo de pertenencia ");
	printf("\n[11] Borrar pantalla");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("===============================================\n");
	fflush(stdin);
	
	return op;
	
}
