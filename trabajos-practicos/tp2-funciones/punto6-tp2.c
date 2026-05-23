#include <stdio.h>
#include <stdlib.h>

/* Ejercicio 6: Dados dos números naturales A y B, se desea calcular el producto de A * B utilizando la
definición del producto:
A * B = A + A + A + . . . + A
B veces*/
int producto (unsigned, unsigned);

int main() {
	
	unsigned A, B;
	
	printf("Ingrese dos numeros naturales para realizar el producto A*B");
	printf("\n A="); scanf("%u", &A);
	printf("\n B="); scanf("%u", &B);	
	
	printf("\n");
	system("pause");
	printf("\nA*B= %d", producto(A,B));
	
	return 0;
}

int producto (unsigned A, unsigned B){
	
	int i, C;
	C=0;
	
	for(i=1;i<=B;i++){
		C+=A;
		printf("\t Parcial: %d", C);
	}
	return C;
}
