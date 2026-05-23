#include <stdio.h>

int main() {
	
	int I, N, b, numero, cont;
	char C;
	
	numero=0;
	cont=0;
	b=0;
	
	printf("Ingrese la cantidad de caracteres del texto:   ");
	scanf("%d", &N);
	
	for(I=1;I<=N;I++){
		
		printf("Ingrese un Caracter: ");
		fflush(stdin);
		scanf("%c", &C);
			
		switch(C){
		case '1': case '2':case '3': case '4':case '5': case '6':case '7': case '8':case '9': case '0':
			if(b==0)
				numero=1;
			break;
		case ' ':
			b=0;
			if(numero==1){
				cont++;
				numero=0;
			}
			break;
		default:
			numero=0;
			b=1;
		}	
			
	}
	
	if (numero == 1)
		cont++;
	
	printf("La cantidad de numeros en el texto es: %d", cont);
	
	
	return 0;
}

