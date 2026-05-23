#include <stdio.h>
#include <stdlib.h>
/*
Ejercicio 19: Dados N caracteres que representan un párrafo, conformados por letras, dígitos y
espacios en blanco. Se pide informar la cantidad de números naturales que se encuentran en el párrafo.
Nota: Considerar que el ingreso se realiza de a un carácter por vez
*/

int main() {
	
	/*Declaracion de variables*/
	char X;
	int n, i, cont=0;
	int numero=0;
	
	/*Entrada de N*/
	printf("Ingrese la cantidad de caracteres a ingresar (incluye letras, espacios en blanco y dígitos): ");
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		
		printf("\nIngrese caracter: "); 	/*Ciclo de ingreso de caracteres*/
		fflush(stdin);
		scanf("%c",&X);
		
		if(X>= '0' && X<= '9'){
			
			if(numero==0)
			{ 								/*Cuando entramos a un número*/
				cont++;
				numero=1;
			}
		}
		else
			numero=0;					 	/*Al salir*/
		
		
	}
	
	printf("\n-----------------------------------------");
	printf("\nLa cantidad de numeros en el texto es: %d", cont); /*Salida*/
	printf("\n-----------------------------------------");	
	
	return 0;
}

