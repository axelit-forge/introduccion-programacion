#include <stdio.h>
#define MAXV 30

typedef int Vec[MAXV];

void CargarVec_R(Vec, int*);
void MostrarVec_R(Vec, int);
void BuscaYElimina(Vec, int);


int main(void) {
	int N;
	Vec V;
	
	printf("\nBienbvenidos a mi segunda prueba de recursividad, ahora, vectores; \n");
	
	CargarVec_R(V, &N);
	
	
	return 0;
}

void Cargar(Vec V, int N){
	if(N>0){
		Cargar(V, N-1);
		printf("V[%d]= ", N);
		scanf("%d", &V[N]);
	}
	
}


void CargarVec_R(Vec V, int* N){
	
	printf("\n Ingrese el tamanio de la lista: "); 
	scanf("%d", N);
	
	Cargar(V, *N);

	
}
