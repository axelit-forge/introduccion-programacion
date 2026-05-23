#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void ingreso (unsigned*, unsigned*);
int randomNum (unsigned, unsigned);

int main() {
	
	unsigned a, b;
	int X, i, K, N, cont;
	
	
	ingreso(&a, &b);				/*Ingreso de rango*/
	printf("\n=======================================");
	printf("\nEl rango a trabajar será de [%d , %d]", a, b);
	printf("\n=======================================");
	printf("\n");
	system("pause");
	
	
	printf("\nIngrese el numero del que generaran multiplos: ");
	scanf("%d", &K);
	printf("\nIngrese la cantidad de multiplos a hallar: ");
	scanf("%d", &N);
	srand(time(NULL));
	
	cont=0;
	i=a;
	while(i<=b&&cont<N){
		X=randomNum(a,b);
		if(X%K==0)
		{
			printf("\nUn multiplo es %d", X);
			cont++;
		}
		i++;
	}
	
	if(i>b)
		printf("\nError------>Quiza no haya tantos multiplos en el intervalo...");
	
	
	
	return 0;
}

void ingreso (unsigned* X, unsigned* Y){	/*Ingreso de rango*/
	
	do{
		if(*X>=*Y)
			printf("\tY DEBE SER MAYOR QUE X\n");
		printf("Ingrese el intervalo\n"); 
		printf("a: "); 
		scanf("%u", X);
		
		printf("b: ");
		scanf("%u", Y);
		
	}while (*X>=*Y);
	
}

int randomNum (unsigned R1, unsigned R2){ /*generador de numero random*/
		
	return rand() % (R2-R1+1) + R1;
}
