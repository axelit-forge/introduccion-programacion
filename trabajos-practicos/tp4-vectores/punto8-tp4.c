#include <stdio.h>

#define tamano 30
/*Ejercicio 8: Dada una lista A de N números enteros, que puede contener números repetidos, calcular*/
/*	el promedio de los números que se encuentran en posiciones impares del arreglo y crear otra lista B*/
/*	conteniendo los elementos de A que sean mayores al promedio calculado. Mostrar ambas listas. */

typedef int array [tamano];

void ingresoListaIncondicionada (array, int*);
void crearVector (array, int, array, int*);
void mostrarVector(array, int);
void salida(array, int, array, int);

int main() {
	array A, B;
	int N, M=0;
	
	ingresoListaIncondicionada (A, &N);
	
	crearVector(A, N, B, &M);
	
	salida(A, N, B, M);
	
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

int promedioVector (array Vector, int Cantidad){
	int i, Acumulador= 0, contador=0;
	
	for(i=1; i<= Cantidad; i+=2){
		Acumulador+= Vector[i];
		contador++;
	}
	
	return Acumulador/contador;
}
	
void crearVector (array V, int N, array B, int * M){
	int prom;
	int i;
	
	prom=promedioVector(V, N);
	
	for(i=1; i<= N; i++){
		if(V[i]>prom){
			(*M)++;
			B[*M]= V[i];
		}
	}
}

void mostrarVector(array V, int N){
	int i;
	printf("\n V{ ");
	
	for(i=1; i<=N; i++){
		printf("%d, ", V[i]);
	}
	printf("}");
}

void salida(array A, int N, array B, int M){
	
	printf("\nEl vector A es:");
	mostrarVector(A, N);
	printf("\n");
	
	printf("\nEl vector B es:");
	mostrarVector(B, M);
	printf("\n");
	
}
