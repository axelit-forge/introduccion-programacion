#include <stdio.h>
#include <ctype.h>
#define tamano 30
/*Ejercicio 3: Se tiene una lista de caracteres que representa una frase conformada con consonantes,*/
/*	vocales en minúsculas y dígitos, el ingreso de la lista se finalizará al ingresar el carácter “/”. Se solicita*/
/*	ingresar un carácter y buscarlo en la lista ingresada informando la primera posición donde se encuentra,*/
/*	borrar de la lista los dígitos presentes y para finalizar ordenar la lista ascendentemente y mostrar la lista*/
/*	resultante.*/
void ingresoFraseIncondicionado (char [], int*);
void busquedaSecuencial (char [], int, int*, char);
void borrarDigito (char [], int*); 	
void OrdenarCharSD(char[], int);
void mostrarVector(char[], int);

int main() {
	
	char Frase [tamano];
	int N, posicion;
	char ingreso;
	
	ingresoFraseIncondicionado(Frase, &N);
	
	printf("\n");
	printf("Ingrese un elemento: ");
	scanf("%c", &ingreso);
	
	busquedaSecuencial (Frase, N, &posicion, ingreso);
	if (posicion==0)
		printf("\n El elemento no está en la lista");
	else
		printf("\n El elemento está primero en la posicion: %d", posicion);
	
	borrarDigito (Frase, &N);
	OrdenarCharSD(Frase, N);
	
	printf("\n");
	mostrarVector(Frase, N);
	
	
	
	return 0;
}

void ingresoFraseIncondicionado (char Frase [], int* Cantidad){
	int i=1;
	
	printf("COLOQUE '/' PARA TERMINAR LA CARGA\n Ingrese el primer elemento: \n");
	printf("F[%d] = ", i);
	scanf("%c%*c", &Frase[1]);
	
	while (Frase[i] != '/'){
		i++;
		printf("F[%d] = ", i);
		scanf("%c%*c", &Frase[i]);
		
	}
	*Cantidad = i-1;
}

void busquedaSecuencial (char V[], int N, int* posicion, char elemento){
	int i=1;
	
	while (i<=N && V[i] != elemento)
		i++;
	if (i>N)
		*posicion=0;
	else
		*posicion=i;
}
	
	
void borrarDigito (char Vector[], int*N){
	int i=1, j;
	
	while (i<= *N){
		if ( '0'<=Vector[i] && '9'>=Vector[i] ){
			for(j=i; j<= *N; j++){
			Vector [j]= Vector [j+1];
			}
			(*N)--;
		}
		else
			i++;
	}
	
}

void mostrarVector(char V[], int N){
	int i;
	printf("\n F{ ");
	
	for(i=1; i<=N; i++){
		printf("%c, ", V[i]);
	}
	printf("}");
}

void OrdenarCharSD(char F[], int N){
	int i, j;
	int aux;
	
	for (i=1;i<N;i++){
		for (j=(i+1); j<=N; j++){
			if(F[i] > F[j]){
				aux=F[i];
				F[i]=F[j];
				F[j]=aux;
			}
		}
	}
}
