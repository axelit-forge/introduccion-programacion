#include <stdio.h>

short menu();
void invertir (int);
void cambio (int*, int*);


int main() {
	
	int A, B;
	short opt;
	
	printf("\t-Ingrese los numeros-\n");
	printf(" A = "); scanf("%d", &A);
	printf(" B = "); scanf("%d", &B);	
	
	opt=menu();
	
	switch(opt){
	case 1: invertir(A); break;
	case 2: invertir(B); break;
	case 3: cambio(&A, &B);
		printf("Nuevos valores: A=%d - B=%d", A, B);
		break;
	default: printf("SALIENDO");
	}
	
	return 0;
}


short menu () {
	
	short op;
	
	do{printf("\n===============================================");
	printf("\nBienvenido, elija la opcion que desee realizar:");
	printf("\n[1] Para mostrar el invertido de A");	
	printf("\n[2] Para mostrar el invertido de B");
	printf("\n[3] Acomodar los valores para que A tenga el mayor num");
	printf("\n[0] Para salir\n");	
	scanf("%hd", &op);
	printf("\n===============================================\n");}while(op>3||op<0); 
	
	return op;
}

void invertir (int num){
	int aux;
	aux=0;
	while(num!=0){
		aux=(aux*10)+(num%10);
		num/=10;
	}
	printf("El numero invertido es: %d", aux);
}

void cambio (int* X, int*Y){
	int Aux;
	if(*X<*Y){
		Aux=*X;
		*X=*Y;
		*Y=Aux;
	}
}


