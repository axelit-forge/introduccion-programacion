#include <stdio.h>


void text(int digito);

int main() {
	
	short digito;
	
	printf("\n Ingrese un dígito: ");
	scanf("%hd" , &digito);
	
	if(digito<10&&digito> -1){
		printf("\n El dígito es ");
		text(digito);}
	else
	   printf("El numero no es un digito");
	
	return 0;
}
void text (int digito){
	switch(digito){
		case 1: printf("Uno"); break;
		case 2:	printf("Dos"); break;
		case 3: printf("Tres"); break;
		case 4: printf("Cuatro"); break;
		case 5: printf("Cinco"); break;
		case 6: printf("Seis"); break;
		case 7: printf("Siete"); break;
		case 8: printf("Ocho"); break;
		case 9: printf("Nueve"); break;
		case 0: printf("Diez"); break;
	
	}
}
