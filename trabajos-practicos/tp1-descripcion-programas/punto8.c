#include <stdio.h>

int main(void) {
	
	/*Def de variables*/
	int A,B,C;
	
	/*Ingreso de datos*/
	printf("\nIngrese el ángulo A:");
	scanf("%d",&A);
	printf("\nIngrese el ángulo B:");
	scanf("%d",&B);
	printf("\nIngrese el ángulo C:");
	scanf("%d",&C);
	
	/*Verificacion de suma de angulos*/
	if(A+B+C!=180)
		printf("\nValores de ángulos inválidos");
	else if (A>90||B>90||C>90)
		printf("\nEs un triangulo Obtusángulo");
		else if (A==90||B==90||C==90)
			printf("\nEs un triangulo Recto");
		else
			printf("\nEs un triangulo Acutángulo");
	
	return 0;
}

