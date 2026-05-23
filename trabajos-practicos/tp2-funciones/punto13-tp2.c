#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingreso (int*, int*);
int randomNum (int, int);
void clas (int);

int main(int argc, char *argv[]) {
	
	int A, B, i, X, N;
	
	ingreso(&A,&B);
	printf("\n=======================================");
	printf("\nEl rango a trabajar será de [%d , %d]", A, B);
	printf("\n=======================================");
	printf("\n");
	system("pause");
	
	printf("Ingrese la cantidad de numeros a generar: "); scanf("%d", &N);
	srand(time(NULL));
	printf("\n LISTA COMPLETA");
	for(i=1;i<=N;i++){
		X=randomNum(A, B);
		printf("\n Numero generado %d", X);
		clas(X);
	}
	return 0;
}

void ingreso (int* X, int* Y){
	
	do{
		if(*X>=*Y)
			printf("\tA DEBE SER MAYOR QUE B\n");
		printf("Ingrese los valores\n"); 
		printf("A: "); 
		scanf("%d", X);
		
		printf("B: ");
		scanf("%d", Y);
		
	}while (*X>=*Y);
	
}

int randomNum (int R1, int R2){
	
	return rand() % (R2-R1+1) + R1;
}

int sumadiv (int num){
	int i, acu=0;
	for(i=1;i<num;i++)
		if(num%i==0)
		acu+=i;
	return acu;
}
	

void clas(int num){
	int div;
	div=sumadiv(num);
	
	if (div>=num)
	printf("\t%d no es deficiente", num);
}		
