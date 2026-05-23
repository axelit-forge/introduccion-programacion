#include <stdio.h>

/*Dados N caracteres que representan un párrafo, conformados solamente por letras y
espacios en blanco. Se pide informar la cantidad de vocales y la cantidad de consonantes que tiene el
párrafo, también la cantidad de palabras que se encontraron.
Nota: Entre las letras del párrafo no hay vocales acentuadas y las palabras se separan por un solo
espacio en blanco. Considerar que el ingreso se realiza de a un carácter por vez.*/

int main() {
	
	/*Declaracion de variables*/
	char X;
	int n, i, contPala=1, contVoc=0, contCons=0;
	
	/*Entrada de N*/
	printf("Ingrese la cantidad de caracteres a ingresar (incluye letras, espacios en blanco): ");
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		
		printf("\nIngrese caracter: "); 	/*Ciclo de ingreso de caracteres*/
		fflush(stdin);
		scanf("%c",&X);
		
		switch(X){
		case 'U': case 'D': case 'C': case 'B': case 'A': contVoc++; break;
		case 'u': case 'd': case 'c': case 'b': case 'a': contVoc++; break;
		case ' ': contPala++;break;
		default: contCons++;
		}
	}
	printf("La cantidad de palabras es %d, de vocaales es %d y de consontantes es %d", contPala, contVoc, contCons);
	
	return 0;

}
