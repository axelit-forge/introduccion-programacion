#include <stdio.h>
#define tamVect 15

typedef int tVect[tamVect];

typedef struct {
	tVect vec;
	int tam;
}tListEnts;

tListEnts cargaEnts(void);
void mostrarEnts(tListEnts);

int main(void) {
	tListEnts A; 
	A = cargaEnts();
	mostrarEnts(A);
	return 0;
}

void ordenVec(tVect V,int tam) {
	int j;
	if(tam>1) {
		V[0] = V[tam];
		j = tam - 1;
		while(V[0]<V[j]) {
			V[j+1] = V[j];
			j = j - 1;
		}
		V[j + 1] = V[0];
	}
}

void cargaVec(tVect V,int tam) {
	if(tam>0) {
		cargaVec(V,tam-1);
		printf("Ingresar un numero entero:\n");
		scanf("%d",&V[tam]);
		ordenVec(V,tam);
	}
}

tListEnts cargaEnts(void) {
	tListEnts aux;
	printf("Ingresar la cantidad de enteros:\n");
	scanf("%d",&aux.tam);
	printf("CARGA DE ENTEROS\n");
	cargaVec(aux.vec,aux.tam);
	
	return aux;
}

void mostrarVec(tVect V,int tam) {
	if(tam>0) {
		mostrarVec(V,tam-1);
		printf("%d ",V[tam]);
	}
}

void mostrarEnts(tListEnts x) {
	printf("Cantidad de enteros: %d\n",x.tam);
	printf("Enteros:\n");
	mostrarVec(x.vec,x.tam);
}

