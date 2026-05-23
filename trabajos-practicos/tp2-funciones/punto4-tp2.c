#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
Ejercicio 4: Dados dos naturales, X e Y, donde X<Y, se necesita generar aleatoriamente dos números reales A y B, pertenecientes a rango [X, Y] y a continuación mostrar un menú que permita calcular y mostrar:
	a) La raíz cuadrada de A.
	b) La potencia de A*B
	c El logaritmo decimal de* B.   */

short menu ();
int randomNum (int, int);
void ingreso (int*, int*);
	
int main() {
	
	int X, Y;
	float A, B;
	short Opt;
	
	ingreso(&X, &Y);
	printf("\n=======================================");
	printf("\nEl rango a trabajar será de [%d , %d]", X, Y);
	printf("\n=======================================");
	printf("\n");
	system("pause");
	
	srand(time(NULL));
	A=(float)randomNum(X, Y);
	B=(float)randomNum(X, Y);
	printf("\n Los numeros generados son A=%f, y B=%f\n", A, B);
	system("pause");
	
	
	Opt=menu();
	
	switch(Opt){
	case 1: printf("La raíz cuadrada de A=%f", sqrt(A)); break;
	case 2: printf("La potencia de A a la B=%f", pow(A, B)); break;
	case 3: printf("El logaritmo decimal de B=%f", log10(B)); break;
	}
	
	
	return 0;
}

void ingreso (int* X, int* Y){
	
	do{
		if(*X>=*Y)
			printf("\tY DEBE SER MAYOR QUE X\n");
		printf("Ingrese los valores\n"); 
		printf("X: "); 
		scanf("%d", X);
		
		printf("Y: ");
		scanf("%d", Y);
		
	}while (*X>=*Y);
	
}
short menu () {
	
	short op;
	
	do{printf("\n===============================================");
	printf("\nBienvenido, elija la opcion que desee realizar:");
	printf("\n[1] Para calcular la Raiz cuadrada de A");	
	printf("\n[2] Para calcular la potencia de A a la B");
	printf("\n[3] Para calcular el logaritmo decimal de B\n");
	scanf("%hd", &op);
	printf("\n===============================================\n");}while(op>3||op<1); 
	
	return op;
}
int randomNum (int R1, int R2){
	
	return rand() % (R2-R1+1) + R1;
}
