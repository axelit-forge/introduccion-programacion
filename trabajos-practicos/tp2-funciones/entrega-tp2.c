#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int lector (char);
int	componer (char, int);

int main() {
	
	int N, i, num, acu;
	char X;
	
	acu=0;
	num=0;
	
	printf("Ingrese la cantidad de caracteres del texto: "); scanf("%d", &N);
	
	for(i=1;i<=N;i++)
	{
		printf("\nIngrese caracter: ");
		fflush(stdin);
		scanf("%c", &X);
		if (lector(X)==1)
		{
			num=componer(X,num);
		}
		else
		{
			acu+=num;
			num=0;
		}
	}
	
	acu+=num;
	printf("La suma de números presentes en el texto es de: %d", acu);
	
	return 0;
}

int lector (char c){
	
	if(isdigit(c)!=0)
		return 1;
	else
		return 0;
	
	
}

int componer (char n, int nro){
	int dig ;
	
	dig=n-'0';
	/*switch(n){
	case '0': dig=0; break;
	case '1': dig=1; break;
	case '2': dig=2; break;
	case '3': dig=3; break;
	case '4': dig=4; break;
	case '5': dig=5; break;
	case '6': dig=6; break;
	case '7': dig=7; break;
	case '8': dig=8; break;
	case '9': dig=9; break;
	}*/
	nro=nro*10+dig;
	
	return nro;
}
