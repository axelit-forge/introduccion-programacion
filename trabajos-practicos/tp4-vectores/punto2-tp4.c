#include <stdio.h>
#define TamVec 20

void cargaVector (int[] , int*);
int menorVector(int[], int);
void mostrarVector(int[], int);
void OrdenarBurbuja(int [], int );
void busquedaSecuencial (int[], int , int*, int);
void mostrarPrimos (int [], int);
void IngresarElemento (int[], int*, int, int);

int main() {
	
	int Vector[TamVec];
	int N, menor;
	int pos, ingreso;
	
	cargaVector(Vector, &N);
	
	menor = menorVector(Vector, N);
	printf("\nEl menor elemento es = %d", menor);

	OrdenarBurbuja(Vector, N);
	
	printf("\n\n El vector ordenado es\n");
	mostrarVector(Vector, N);
	
	printf("\nIngrese el elemento a ingresar: ");
	scanf("%d", &ingreso);
	busquedaSecuencial(Vector, N, &pos, ingreso);
	IngresarElemento(Vector, &N, pos, ingreso);
	
	mostrarVector(Vector, N);
	
	printf("\n\nLista de numeros primos:\n");
	mostrarPrimos(Vector, N);
	
	return 0;
}

void cargaVector (int Vec[] , int* N){
	int i;
	
	printf ("Ingrese la cantidad de elementos: ");
	scanf ("%d", N);
	
	for(i=1; i <= *N ;i++){
		printf("[%d] : ", i); 
		scanf("%d", &Vec[i]);
	}
}

int menorVector(int V[], int N){
	int i, menor;
	
	menor= V[1];
	for(i=2; i<=N; i++)
	{
		if (V[i]< menor)
			menor=V[i];
	}
	return menor;
}
	
void mostrarVector(int V[], int N){
	int i;
	printf("\n V{ ");
	
	for(i=1; i<=N; i++){
		printf("%d, ", V[i]);
	}
	printf("}");
}
	
	
void OrdenarBurbuja(int V[], int N){
	int C, P, copia;
	
	for (P=2; P<=N; P++){
		for (C=N; C>=P; C--){
			if (V[C-1]>V[C])
			{
			copia= V[C];
			V[C]= V[C-1];
			V[C-1]= copia;
			}
		}
	}
}
	
void busquedaSecuencial (int V[], int N, int* posicion, int elemento){
	int i=1;
	
	while (i<=N && V[i]< elemento)
		i++;
	*posicion=i;
}
	
int primo (int num){
	int pd, lim;
	pd=2;
	lim=num/2;

	while(pd<=lim&&num%pd!=0)
		pd++;

	return (pd>lim&&num!=1);
}

void IngresarElemento (int V[], int* N, int posicion, int elemento){
	int i;
	
	for(i= *N; i>=posicion ;i--){
		V[i+1]=V[i];
	}
	V[i+1]=elemento;
	(*N)++;
}
	
	
void mostrarPrimos (int V[], int N){
	int i;
	for(i=1; i<=N; i++){
		if (primo(V[i]))
			printf("- %d ", V[i]);
	}
}
