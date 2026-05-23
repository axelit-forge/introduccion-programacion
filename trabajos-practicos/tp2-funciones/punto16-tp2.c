#include <stdio.h>
#include <ctype.h>

short lector (char);

int main() {
	
	int N, i, contV, contD, contC;
	char X;
	short b;
	
	contV=0; contD=0; contC=0;
	
	printf("Ingrese la cantidad de caracteres del texto: "); scanf("%d", &N);
	
	for(i=1;i<=N;i++)
	{
		printf("\nIngrese caracter: ");
		fflush(stdin);
		scanf("%c", &X);
		b=lector(X);
		if (b==1)
			contD++;
		else
			if(b==0)
			contC++;
			else
				if(b==-1)
				contV++;
	}
	
	printf("\n\n La cantidad de vocales en el texto es %d", contV);
	printf("\n La cantidad de consonantes en el texto es %d", contC);
	printf("\n La cantidad de digitos en el texto es %d", contD);
	return 0;
}

short lector(char C){
	
	short b;
	
	if(isdigit(C))
		b=1;
	else
	{
		switch(C){
		case 'a': case 'e': case 'i': case 'o': case 'u': b=-1; break;
		default: if (isalpha(C)) b=0;
		}
	}
	return b;
}
