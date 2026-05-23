#include <stdio.h>

typedef int Vec[30];

typedef struct{
	Vec num;
	int N;
}Salida;

Salida VectorCMayor( Vec V, int M){
	int i, j, cont=0, mayor=0;
	Salida Hola;
	
	Hola.N=0;
	
	for(i=1; i<=M; i++){
		cont=1;
		for(j=i+1; j<=M; j++){
			if(V[i]==V[j]){
				cont++;
				if(cont>mayor)
					mayor=cont;
			}
		}
	}
	
	for(i=1; i<=M; i++){
		cont=1;
		for(j=i+1; j<=M; j++){
			
			if(V[i]==V[j])
				cont++;
		}
		if(cont==mayor){
			Hola.N= Hola.N+1;
			Hola.num[Hola.N]=V[i];
		}
	}
	
	return Hola;
}





int main() {
	Salida V;
	int i;
	Vec W={1,2,3,3,10,4,5,5,6,7,7,8,10};
	int M=13;
	
	V=VectorCMayor(W, M);
	for(i=1;i<= V.N; i++){
		
		printf(" %d, ", V.num[i]);
	}
	
	
	return 0;
}

