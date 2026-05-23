#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresarNat(int*);
short capicua (long);
int randomNum (int, int);
long prodDig (int);

int main() {
	
	int N, i, Y;
	long X;
	srand(time(NULL));
	
	ingresarNat(&N);
	for(i=1;i<=N;i++){
		
	X=randomNum(1,999999);
	printf ("\nNumero generado: %ld", X);
	if (capicua(X)==1)
		printf("\t--->Es capicua");
	else{
	Y=prodDig(X);
	printf("\t---> No es capicua, Y=%d",Y);
	}
	}
	return 0;
}

short capicua (long num){
	long aux, Xc;
	short b=0;
	Xc=num;
	aux=0;
	while(num!=0){
		aux=(aux*10)+(num%10);
		num/=10;
	}
	if(Xc==num)
		b=1;
	return b;
}
void ingresarNat(int*Num){
	do{
		if(*Num<1) printf("EL NUMERO DEBE SER NATURAL");	
		printf("\n Ingrese el N: ");
		scanf("%d", Num);}while(*Num<1);
}

int randomNum (int R1, int R2){
	
	return rand() % (R2-R1+1) + R1;
}
	
long prodDig (int num){
	int dig;
	long acu=1;
	
	while(num!=0){
		dig=num%10;
		acu*=dig;
		num/=10;
	}
	return acu;
}

