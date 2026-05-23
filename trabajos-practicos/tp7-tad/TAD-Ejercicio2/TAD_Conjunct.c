#include "TAD_Conjunct.h"
#include <stdlib.h>
#include <stdio.h>


int Pertenece(TConjunto C, char X){
	int i;
	i=1;
	
	while(i<= C.N && X!=C.Elem[i])
		i++;
	
	return(i<=C.N);
}
int ContieneA(TConjunto A, TConjunto B){
	int i, b;
	i=1; b=0;
	
	while(i<= A.N && b==0){
		if (!Pertenece(B, A.Elem[i]))
			b=1;
		i++;
	}
	
	return (b==0);
}

int randomNum(int R1, int R2){		/*privado*/
	
	return random() %(R2-R1+1) + R1;
}
	
void IngresoOrden(TConjunto* C, char X, int pos){
	int j;
	j=pos;
	C->Elem[0]=X;
	while(C->Elem[j]> X){
		C->Elem[j+1]=C->Elem[j];
		j--;
	}
	C->Elem[j+1]= X;
}
	
void Gen(TConjunto* C){		/*privado*/
	int i;
	char x;
	i=0;

	while(i<= C->N){
		x= randomNum(65, 122);
		if(!Pertenece(*C, x)){
		   IngresoOrden(C, x, i);
		   i++;
		}
	}
}
	
TConjunto GenConjunto (){
	TConjunto Nvo;
	Nvo.N= randomNum(1, MAXC);
	
	Gen(&Nvo);
	
	return Nvo;
}
void ShowConjunto(TConjunto A){
	int i;
	printf("\nConjunto:{ ");
	for(i=1; i< A.N; i++){
		printf("%c , ", A.Elem[i]);
	}
	printf("%c}", A.Elem[A.N]);
}
void AgregarElem(TConjunto* A, char X){
	
	if(A->N == MAXC-1)
		printf("Conjunto lleno");
	else {
		if(!Pertenece(*A, X)){
			IngresoOrden(A, X, A->N);
			A->N++;
			printf("\t ingresado!");
		}
		else
			printf("\t elemento ya presente");
	}
}
TConjunto Union(TConjunto A, TConjunto B){
	TConjunto C;
	int i, j, lim;
	C.N=1;
	lim= MAXC-1;
	
	for(i=1; i<=A.N ; i++){
		if(C.N<lim){
			C.Elem[C.N]=A.Elem[i];
			C.N++;
		}
	}
	for(j=1; j<=B.N ; j++){
		if(C.N<lim && !Pertenece(C, B.Elem[j])){
			IngresoOrden(&C, B.Elem[j], C.N);
		}
	}
	
	return C;
}
TConjunto Interseccion(TConjunto A, TConjunto B){
	TConjunto C;
	int i;
	C.N=0;
	
	for(i=1; i<=A.N ; i++){
		if(Pertenece(B, A.Elem[i])){
			C.N++;
			C.Elem[C.N]=A.Elem[i];
		}
	}
	
	return C;
}
TConjunto Resta(TConjunto X, TConjunto Y){
	TConjunto C;
	int i;
	C.N=0;
	
	for(i=1; i<=X.N ; i++){
		if(!Pertenece(Y, X.Elem[i])){
			C.N++;
			C.Elem[C.N]=X.Elem[i];
		}
	}
	return C;
}
TConjunto DifSimetrica(TConjunto A, TConjunto B){
	TConjunto C, D, E;
	
	C=Union(A, B);
	D=Interseccion(A, B);
	E=Resta(C, D);
	return E;
}
int Cardinal(TConjunto A){
	return A.N;
}
