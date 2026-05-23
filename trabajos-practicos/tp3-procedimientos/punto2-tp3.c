#include <stdio.h>

void segToTime(long, int*, int*, int*);
void ingresarNat(long*);
void altera (int*, int*);
void cambio (int*, int*);

int main() {
	long Segundos_totales;
	int hora, minut, seg;
	int A, B;
	short op;
	
	ingresarNat(&Segundos_totales);
	segToTime(Segundos_totales, &hora, &minut, &seg);
	
	printf("\n-->Horas= %d - Minutos= %d - Segundos= %d", hora, minut, seg);
	
	printf("\n	Ingrese A: ");
	scanf("%d", &A);
	
	printf("\n	Ingrese B: ");
	scanf("%d", &B);
	
	printf("\n Elija que quiere hacer: ");
	printf("1. Manipule dos números enteros quitando la última cifra del primero y añadiéndola al final del segundo.");
	printf("2. intercambie sus valores.");
	scanf("%hd", &op);
	
	if(op==1){
		altera(&A, &B);
		printf("Valor de A = %d, B = %d", A, B);
	}
	else{
	   cambio(&A, &B);
		printf("Valor de A = %d, B = %d", A, B);
	}
		return 0;
}


void segToTime(long segtotal, int*hour, int*minut, int*seg){
	
	*hour = segtotal /3600;
	*minut = segtotal%3600/60;
	*seg = segtotal%60;
	
}

void ingresarNat(long*Num){
	do{
		if(*Num<1) printf("EL NUMERO DEBE SER NATURAL");	
		printf("Ingrese la cantidad de segundos totales: ");
		scanf("%ld", Num);}while(*Num<1);
}
	
void altera (int* X, int* Y){
	int d;
	
	d=*X%10;
	*X=*X/10;
	*Y=*Y*10;
	*Y=*Y+d;
}
	
void cambio (int* X, int*Y){
	int Aux;
	Aux=*X;
	*X=*Y;
	*Y=Aux;
}
