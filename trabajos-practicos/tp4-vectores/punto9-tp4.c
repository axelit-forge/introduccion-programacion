#include <stdio.h>

#define tamano 30

/*Ejercicio 9: Dada una lista A de M números naturales, se solicita crear un vector P que contenga la*/
/*	posición de los elementos de A, para que la lista se recorra ordenada de menor a mayor. Usar el vector*/
/*	P para determinar cuántos elementos de A se encuentran en la posición correcta, de estar ordenado.*/

typedef int array [tamano];

void ingresoListaIncondicionada (array, int*);
void crearVector (array, int, array, int*);
void mostrarVector(array, int);
void salida(array, int, array);

int main() {
	array A, P;
	int N;
	
	ingresoListaIncondicionada (A, &N);
	
/*	crearVector(A, N, P);*/
	
	salida(A, N, P);
	
	
	return 0;
}

void ingresoListaIncondicionada (array V, int*Cantidad){
	int i;
	
	printf("Ingrese la cantidad de numeros de la lista: ");
	scanf("%d", Cantidad);
	
	for(i=1 ;i <= *Cantidad ; i++){
		printf("A[%d] = ", i);
		scanf("%d", &V[i]);
	}	
}
	
/*void crearVector (array V, int N, array B){*/
/*	int i;*/
/*	int elemento;*/
	
/*	for(i=1; i<= N; i++){*/
/*		elemento=V[i];*/
/*		ingresoBaraja(V, N, P, elemento, i);*/
/*	}*/
/*}*/

void mostrarVector(array V, int N){
	int i;
	printf("\n V{ ");
	
	for(i=1; i<=N; i++){
		printf("%d, ", V[i]);
	}
	printf("}");
}
	
void salida(array A, int N, array P){
	
	printf("\nEl vector A es:");
	mostrarVector(A, N);
	printf("\n");
	
	printf("\nEl vector de posiciones es:");
	mostrarVector(P, N);
	printf("\n");
	
}
