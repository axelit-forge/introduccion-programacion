#include <stdio.h>
#include <stdlib.h>

void ingresarFracc (int*, int*);
int MaxCDiv (int, int);
void reduc(int, int*, int*);
void signo (int*, int*);

int main () {
	
	int A, B, mcd;
	
	
	printf("-->Ingrese 0-0 para finalizar la carga");
	ingresarFracc (&A, &B);
	
	while (A!=0&&B!=0){
		
		signo(&A,&B);
		
		mcd=MaxCDiv(A,B);
		
		reduc(mcd, &A,&B);
		
		if (mcd==1)
			printf("\tLa funcion es irreducible, %d/%d", A, B);
		else
			printf("\tLa funcion reducida es %d/%d", A, B);
		
		ingresarFracc(&A,&B);
		
	}
	
	return 0;
}

void acomode (int* X, int* Y){
	int Xr;
	if (*X<*Y){
		Xr=*X;
		*X=*Y;
		*Y=Xr;
	}	
	
}
	
int MaxCDiv (int A, int B){
	
	int McD;
	A=abs(A);
	B=abs(B);
	acomode(&A,&B);
	
	while(A!=B){
		A=A-B;
		acomode (&A,&B);
	}
	McD=A;

	return McD;
}
void reduc(int McD, int*A, int*B){

	McD=MaxCDiv(*A,*B);
	
	*A=*A/McD;
	*B=*B/McD;
}

void signo (int*A, int*B){
	if(*B<0){
	*A=*A*(-1);
	*B=*B*(-1);
	}	
}

void ingresarFracc (int* A, int* B){
	
	printf("\n-------------------------\nIngrese la fracción: ");
	printf("\n A= "); scanf("%d",A);
	printf(" B= "); scanf("%d",B);
	
}
