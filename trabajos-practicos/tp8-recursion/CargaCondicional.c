#include <stdio.h>
#define MAXV 30
typedef int TVec[MAXV];

void Carga(TVec , int*);
void Muestra(TVec, int);

int main() {
	TVec V;
	int n;
	
	Carga(V, &n);
	Muestra(V, n);
	
	return 0;
}

void CargaSubida(TVec V, int *N){
	int Aux;
	
	printf("\n Ingrese el numero: ");
	scanf("%d", &Aux);
	if (Aux != 0) {
/*		CargaSubida(V, N);   */
/*		*N = *N + 1; 	*/			/*Carga en subida Necesita las 2 ssentencias en este orden*/
		V[*N] = Aux; 
		*N = *N + 1;
		CargaSubida(V, N); 			/*Carga en bajada necesita las 2 sentencias en este orden*/
	} else {
		*N = *N - 1;                
	}
}


void Carga(TVec V, int* tam){
	
	*tam= 1;
	printf("\n El ciclo se corta cuando ingrese 0");
	CargaSubida(V, tam);

	
}
void Muestra(TVec V, int tam){
	
	if(tam>0){
		Muestra(V, tam-1);
		printf("\nV[%d]= %d",tam, V[tam]);
	}
}
