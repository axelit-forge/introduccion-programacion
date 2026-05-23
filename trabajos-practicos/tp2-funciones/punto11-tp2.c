#include <stdio.h>

/*Ejercicio 11: Dados una cantidad no determinada de números naturales, mostrar para cada uno de ellos
si se trata de un número Deficiente, Abundante o Perfecto
Nota: Un número natural X se dice que es deficiente si la suma de sus divisores naturales (excepto el
mismo número) es menor a X. Si la suma de sus divisores es mayor a X, se dice que el número es
abundante y si es igual a X se dice que es perfecto.
Ejercicio 12: Dado un número natural N, generar al azar N*/
short clas (int);
void ingresarNat(int*Num);

int main() {
	
	int X;
	short b;
	
	ingresarNat(&X);
	
	while(X>0){
	
	b=clas(X);
	if(b==0)
		printf("\n%d es un numero deficiente", X);
	else
		if(b==1)
		printf("\n%d es un numero abundante", X);
		else
		printf("\n%d es un numero perfecto", X);
	ingresarNat(&X);
	}
	return 0;
}

void ingresarNat(int*Num){
	printf("\n Ingrese el X: ");
	scanf("%d", Num);
}

int sumadiv (int num){
	int i, acu=0;
	for(i=1;i<num;i++)
		if(num%i==0)
		acu+=i;
	return acu;
}

short clas(int num){
	short b;
	int div;
	div=sumadiv(num);
	
	if(div<num)
		b=0;
	else
		if (div>num)
			b=1;
		else 
			b=2;
	return b;
}
