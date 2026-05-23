#include <stdio.h>
#include <stdlib.h>

void ingresarFracc (int*, int*);
int MaxCDiv (int, int);
void reduc(int, int*, int*);
void signo (int*, int*);

int main () {

	int A, B, mcd;


	printf("-->Ingrese B=0 para finalizar la carga");
	ingresarFracc (&A, &B);

	while (B!=0){

	signo(&A,&B);
	if(A!=0)
		mcd=MaxCDiv(A,B);
	else
		mcd=B;

	if (mcd!=1){
		reduc(mcd, &A,&B);
		printf("\tLa fraccion reducida es %d/%d", A, B);
		
	}
	else
	printf("\tLa fraccion es irreducible, %d/%d", A, B);

	ingresarFracc(&A,&B);

}

return 0;
}


int MaxCDiv (int A, int B){

	A=abs(A);
	B=abs(B);
	
	while (A != B) 
	{
		if (A > B) 
			A = A - B; 
		else
			B = B - A;
	}

	return A;
}
	
void reduc(int McD, int*A, int*B){

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
