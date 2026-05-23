#include <stdio.h>
#include <stdlib.h>


void ingresarNat(int*);
int divisores (int);
int primo (int);
long conversor (int, int);

int main() {
	int X, div, b;
	long Xc;
	
	ingresarNat(&X);
	div=divisores(X);
	printf("La cantidad de divisores naturales de %d es %d\n", X, div);
	system("pause");
	
	if(primo(div)==1){
		b=2;
		printf("\n %d es un numero primo\n", div);
	}
	else{
	   b=9;
	   printf("\n %d no es un numero primo\n", div);
	}
	system("pause");
	
	Xc=conversor(X,b);
	printf("\n El numero %d en base %d es= %ld", X, b, Xc);
	
	return 0;
}


int divisores (int num){
	int i, cont=0;
	for(i=1;i<=num;i++)
		if(num%i==0)
		cont++;
	return cont;
}

int primo (int num){
	int pd, lim;
	pd=2;
	lim=num/2;
	
	while(pd<=lim&&num%pd!=0)
		pd++;
	if(pd>lim&&num!=1)
		pd=1;
	else
		pd=0;
	return pd;
}

void ingresarNat(int*Num){
	do{
	if(*Num<1) printf("EL NUMERO DEBE SER NATURAL");	
	printf("\n Ingrese el X: ");
	scanf("%d", Num);}while(*Num<1);
}	

int exponente(int x, int exp){
	int i, rto=1;
	for(i=1;i<=exp;i++){
		rto*=x;
	}
	return rto;
}
	
long conversor (int num, int base){
	int exp, dig, aux=0;
	exp=0;
	while(num!=0){
		dig=num%base;
		aux+=dig*exponente(10,exp);
		num/=base;
		exp++;
	}
	return aux;
}
