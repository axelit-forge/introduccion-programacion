#include <stdio.h>

void ingresarNat(int*);
short verDig (int);
int max(int, int);
int min(int, int);

int main() {
	
	int X, mayor, menor;
	short b;
	mayor=0;
	menor=0;
	
	ingresarNat(&X);
	b=verDig(X);
	while(X>0){
	if(b==0){
		printf("\nNumero formado solo por digitos pares %d", X);
		printf("\n");
		
		mayor= max(X, mayor);
		menor= min(X, menor);
	}
	ingresarNat(&X);
	b=verDig(X);
	}
	
	printf("\n El numero mayor fue %d", mayor);
	printf("\n El numero menor fue %d", menor);
	
	return 0;
}


void ingresarNat(int*Num){
	printf("\n Ingrese el X: ");
	scanf("%d", Num);
}
	
short verDig (int num){
	int dig;
	short b=0;
	
	while(num!=0&&b==0){
		dig=num%10;
		if(dig%2==1)
			b=1;
		num/=10;
	}
	return b;
}

int max(int num, int mayor){
	if (mayor==0)
		mayor=num;
	else
		if(mayor<num)
		mayor=num;
	return mayor;
}

int min(int num, int menor){
	if (menor==0)
		menor=num;
	else
		if(menor>num)
		menor=num;
	return menor;
}
