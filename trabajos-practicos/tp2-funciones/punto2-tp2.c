#include <stdio.h>
#include <math.h>


int main() {
	
	float A;
	short Option;
	
	printf("Ingrese el numero A: ");
	scanf("%f", &A);
	
	do{printf("\n==========================MENU DE OPCIONES==========================");
	printf("\nIngrese [1] para calcular el seno de A");
	printf("\nIngrese [2] para calcular el logaritmo natural de A");
	printf("\nIngrese [3] para calcular el valor absoluto de A");
	printf("\nIngrese [0] para salir\n____\n");
	scanf("%hd", &Option);}while(Option<0||Option>3);
	
	
	switch(Option){
	case 1: printf("El seno de %f es = %f", A, sin(A)); break;
	case 2: printf("El logaritmo natural de %f es = %f", A, log(A)); break;
	case 3: printf("El seno de %f es = %f", A, fabs(A)); break;
	case 0: printf("=====Gracias por usar====="); break;
	}
	
	return 0;
}
