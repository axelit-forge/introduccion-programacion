#include <stdio.h>

/*Ejercicio 7: Escribir la cabecera e implementar módulos que realicen las siguientes operaciones:
	a) Calcular la cantidad de divisores naturales de un número natural X.
	b) Determinar si un número natural X es primo.
	c) Comparar dos números reales A y B, devolviendo 1 si A>B; 0 si A=B o -1 si A<B.
		d) Invertir un número entero X.
		Probar los módulos mediante un programa que presente un menú con las cuatro operaciones
		implementadas. 
*/
short menu ();
void ingresarNat(int*);
void ingresarRe(float*, float*);
int divisores (int);
int invertir (int);
int primo (int);
short comparar(float, float);

int main() {
	
	short op, b;
	int X;
	float A, B;
	
	op= menu();
	
	switch(op){
	case 1: 
		ingresarNat(&X);
		printf("\nLa cantidad de divisores naturales de X es: %d", divisores(X));
		break;
	case 2: 
		ingresarNat(&X);
		if(primo(X)==1)
			printf("\n%d es un numero primo", X);
		else
			printf("\n%d no es un numero primo", X); 
		break;
	case 3: 
		ingresarRe(&A,&B);
		b=comparar(A,B); 
		switch(b){
		case 1: printf("\n%f es mayor que %f", A, B); break;
		case 0: printf("\n%f es igual que %f", A, B); break;
		case -1: printf("\n%f es menor que %f", A, B); break;
		}
		break;
	case 4:
		ingresarNat(&X);
		printf("\nEl num %d invertido es: %d",X, invertir(X)); 
		break;
	default: printf("\n-->SALIDA");
	}
	
	
	return 0;
}

short menu () {
	
	short op;
	
	do{printf("\n===============================================");
	printf("\nBienvenido, elija la opcion que desee realizar:");
	printf("\n[1] Para mostrar la cantidad de divisores naturales de un X");	
	printf("\n[2] Para Determinar si un X es primo");
	printf("\n[3] Para comparar dos numeros reales A y B");
	printf("\n[4] Para invertir un numero X");
	printf("\n[0] Para salir\n");
	scanf("%hd", &op);
	printf("\n===============================================\n");}while(op>4||op<0); 
	
	return op;
}

void ingresarNat(int*Num){
	do{
	if(*Num<1) printf("EL NUMERO DEBE SER NATURAL");	
	printf("\n Ingrese el X: ");
	scanf("%d", Num);}while(*Num<1);
}

void ingresarRe(float*A, float*B){
	printf("\n Ingrese los numeros:");
	printf("A: ");
	scanf("%f", A);
	printf("B: ");
	scanf("%f", B);
}

int divisores (int num){
	int i, cont=0;
	for(i=1;i<=num;i++)
		if(num%i==0)
		cont++;
	return cont;
}

int invertir (int num){
	int aux;
	aux=0;
	while(num!=0){
		aux=(aux*10)+(num%10);
		num/=10;
	}
	return aux;
}

int primo (int num){
	int pd, lim;
	pd=2;
	lim=num/2;
	
	while(pd<=lim&&num%pd!=0)
		pd++;
	if(pd>lim&&num!=1)
		pd=1;
	else
		pd=0;
	return pd;
}
	
short comparar (float A, float B){
	short b;
	if(A>B)
		b=1;
	else
		if(A==B)
		b=0;
		else
		b=-1;
	return b;
}
