#include <stdio.h>
#include <string.h>
#define tamano 6

typedef char Tcad[tamano];

int main() {
	Tcad Frase, Frase2;
	
	
	printf("Ingrese la cadena: ");
	scanf("%s", Frase); 
	fflush(stdin);
	printf("\n\nIngrese otra frase: ");
	gets(Frase2);
	
	
	printf("\nFrase ingresada: %s", Frase);
	
	printf("\nFrase ingresada: ");
	puts(Frase2);
	
	return 0;
}

