#include <stdio.h>
#include <stdlib.h>

/*Ejercicio 4: Cree un programa que ingrese una fracción de la forma A/B y que a continuación devuelva
la fracción irreductible equivalente. ejemplo se A= 6 y B= 8; ( 6 / 8 )entonces Ar= 3 y Br= 4 ( 3 / 4 )
Nota: Generar un procedimiento que reciba A y B, que devuelva Ar y Br*/
int MaxCDiv (int, int);
void reduc(int, int*, int*);
void signo (int*, int*);
void ingresarF (int*, int*);
	
int main() {
	int A, B;
	int Ar;
	
	ingresarF(&A, &B);
	Ar=MaxCDiv(A, B);
	reduc(Ar, &A, &B);
	
	
	printf("La faccion irreducble es %d/%d", A,B);
	
	
	return 0;
}

void ingresarF (int*denom, int*div){
	
	printf("Ingrese denominador: "); scanf("%d", &*denom);
	do{ if (*div==0) printf("EL DIVISOR NO PUEDE SER 0\n");
		printf("Ingrese divisor: "); scanf("%d", &*div);
	} while(*div==0);

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
