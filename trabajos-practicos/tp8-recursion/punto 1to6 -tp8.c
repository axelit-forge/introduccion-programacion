#include <stdio.h>
#include <stdlib.h>

int Fact_R(int);
int DigEnNumero_R(int, int);
void Clasificacion(int);
void averigua(int, int);
int Resto_R(int, int);
void MostrarDig(int);
int Fibo(int );


int main() {
	int F, num, dig;
	int x;
	
	printf("\nBIENVENIDO A MI TEST DE RECURSIVIDAD\n");
	
	/*	Ejercicio 6: La siguiente función retorna el enésimo elemento de la sucesión de Fibonacci, realice el*/
	/*		árbol de llamadas para n=4 y para n=7. Pruebe la función fibo, con n= 10, 20, 30, 40, 44, 45, 46, 47, 48,*/
	/*		49, 50 y 51. ¿Qué observa? ¿Por qué?*/
	printf("\n Ingrese un nuevo numero, para hacer su fibonacci: ");
	scanf("%d",&x); 
	printf("Fibo(%d)= %d",x, Fibo(x));
	
	
	
/*	Ejercicio 1: Dado el módulo iterativo que calcula el factorial de un número natural, se solicita replantearlo*/
/*		recursivamente y realizar la traza con num=6.*/
	printf("\nFactorial de: "); scanf("%d",&F);
	printf("\nResultado: %d", Fact_R(F));
	
/*	Ejercicio 2:) Dado un dígito D, determinar si pertenece a un número entero positivo N. Realizar la traza para*/
/*		D=1 y X= 45673.*/
/*		b) Dado un número natural, indicar si el mismo es perfecto, abundante o deficiente*/
	
	printf("\nIngrese un nuevo numero, y un digito");
	printf("\n Numero: "); scanf("%d", &num);
	printf("\n Digito: "); scanf("%d", &dig);
	if(DigEnNumero_R(num, dig)==0)
		printf("\nEl digito no pertenece\n");
	else
		printf("\n el digito, pertenece al numero\n");
	
	Clasificacion(num);
	
	
/*	Ejercicio 3: Realice la traza del siguiente programa con los valores 30 y 525. Elabore una consigna*/
/*		indicando qué hace el programa.*/	printf("\n Ingrese un número natural, para hallar los factores: ");
	scanf("%d",&x); averigua(x,2);	/*El programa está averiguando los factores de un numero x*/
	
/*	Ejercicio 4:a función permite encontrar el resto de la división entera entre X e Y.*/
	printf("\nIngrese un nuevo numero y su cociente, para hallar el resto: ");
	printf("\n Numero: "); scanf("%d", &num);
	printf("\n Cociente: "); scanf("%d", &dig);
	printf("\n El resto es %d", Resto_R(num, dig));
	
	
/*	Ejercicio 5: Mostrar los dígitos de un número natural X de derecha a izquierda. Realizar la traza para X=*/
/*		45673. Modificar el módulo para que muestre los dígitos de izquierda a derecha. */
	printf("\n Ingrese un nuevo numero, para mostrar sus digitos: ");
	scanf("%d",&x); MostrarDig(x);
	

	return 0;
}

int Fact_R(int F){
	if(F>1)
		return F*Fact_R(F-1);
	else
		return 1;
}
int DigEnNumero_R(int Num, int Dig){
	if(Num==0)
		return 0;
	else{
		if(Num%10==Dig)
			return 1;
		else
			return DigEnNumero_R(Num/10, Dig);
	}
}
	
int SumaDiv(int num, int divisor){
	if(divisor==num)
		return 0;
	else{
		if (num%divisor==0)
			return SumaDiv(num, divisor+1)+divisor;
		else
			return SumaDiv(num, divisor+1);
	}
}
	
	
	
void Clasificacion(int N){
	int SD;
	SD= SumaDiv(N, 1);
	if (SD == N)
		printf("%d es Perfecto\n", N);
	else if (SD > N)
		printf("%d es Abundante\n", N);
	else
		printf("%d es Deficiente\n", N);	
}

void averigua(int N, int f){
	if (N>1){ 
		if (N%f==0)
		{ 
			printf("\t %d",f);
			averigua(N/f, f);
		}
		else 
			averigua(N, f+1);
	}
	else printf("\t %d", 1);
}

int Resto_R(int X, int Y){
	if(X>=Y)
		return Resto_R(X-Y, Y);
	else
		return X;
}

void MostrarDig(int X){
	
	if(X!=0){
		MostrarDig(X/10);
		printf("\t %d", X%10);
	/*	MostrarDig(X/10);*/
	}
}
int Fibo(int X){
	if(X<2)
		return 1;
	else
		return Fibo(X-1) + Fibo(X-2);
}
