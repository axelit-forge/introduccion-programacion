#include <stdio.h>
#include <stdlib.h>

/*Ejercicio 7: Diseñe un programa que permita el ingreso de N fracciones de la forma (A/B) y muestre la
mayor y la menor de ellas, indicando además su expresión irreductible.
Nota: reutilizar el modulo generado en el inciso 4*/
void ingresarFracc (int*, int*);
int MaxCDiv (int, int);
void reduc(int, int*, int*);
void signo (int*, int*);
void mayorFracc(int, int, int*, int*);
void menorFracc(int, int, int*, int*);

int main(){
	
	int A, B, mcd;
	int mayorA, mayorB, menorA, menorB;
	
	
	printf("-->Ingrese B=0 para finalizar la carga");
	ingresarFracc (&A, &B);
	
	menorA = A; menorB = B;
	mayorA = A; mayorB = B;
	
	while (B!=0){
		
		signo(&A,&B);
		
		menorFracc(A,B, &menorA, &menorB);
		mayorFracc(A,B, &mayorA, &mayorB);
		
		ingresarFracc(&A,&B);
	}
	
	
	if(menorA!=0)
		mcd=MaxCDiv(menorA,menorB);
	else
		mcd=menorB;
	
	reduc(mcd, &menorA,&menorB);
	printf("\tLa menor fraccion reducida es %d/%d", menorA, menorB);

	

	if(mayorA!=0)
		mcd=MaxCDiv(mayorA,mayorB);
	else
		mcd=mayorB;
	
	reduc(mcd, &mayorA,&mayorB);
	printf("\tLa mayor fraccion reducida es %d/%d", mayorA, mayorB);
		
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
	
	
void menorFracc (int denom, int divisor, int*Amenor, int*Bmenor){
	
	int X, Y;
	
	X=denom**Bmenor;
	Y=*Amenor*divisor;
	
	if (X<Y) {
		*Amenor=denom;
		*Bmenor=divisor;
	}
	
}
void mayorFracc (int denom, int divisor, int*Amayor, int*Bmayor){
	
	int X, Y;
	
	X=denom * *Bmayor;
	Y=*Amayor * divisor;
	
	if (X>Y) {
		*Amayor=denom;
		*Bmayor=divisor;
	}
	
}
