#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamano 30

/*Ejercicio 5: Generar aleatoriamente una lista A de tamaño N, que simula notas de un examen parcial,*/
/*	entre 0 y 100. A continuación, determinar la/las notas modales (las que más se repiten).*/

typedef int array [tamano];

int randomNum (unsigned, unsigned);
void GenerarLista (array, int*);
int FrecuenciaMayor(array, int);
void mostrarVector(array, int );
void MostrarFrec (array, int, int );


int main() {
	
	int N;
	array Vector;
	int FrecuenciaMax;
	
	srand(time(NULL));
	
	GenerarLista(Vector, &N);
	mostrarVector(Vector, N);
	
	FrecuenciaMax= FrecuenciaMayor(Vector, N);
	
	MostrarFrec(Vector, N, FrecuenciaMax);
	
	
	return 0;
}

void GenerarLista (array Vector, int* Cantidad){
	int i;
	
	printf("Ingrese el tamaño de la lista: ");
	scanf("%d", Cantidad);
	
	for (i=1;i<=*Cantidad;i++){
		Vector[i]= randomNum(0, 100);
	}	
}
	
int randomNum (unsigned R1, unsigned R2){ /*generador de numero random*/
	
	return rand() % (R2-R1+1) + R1;
}


int Frecuencia (array Vector, int Cantidad, int pos){
	int j, i;
	int Frecuencia = 1; 
	
	for (j = 1; j < pos; j++) {
		if (Vector[j] == Vector[pos]) {
			return 0; 
		}
	}
	
	for (i = pos + 1; i <= Cantidad; i++) {
		if (Vector[i] == Vector[pos]) {
			Frecuencia++;
		}
	}
	
	return Frecuencia;
}
	

int FrecuenciaMayor(array Vector, int Cantidad){
	int i, Frec=0, Mayor=0;
	
	for (i=1; i<= Cantidad; i++){
		
		Frec= Frecuencia(Vector, Cantidad, i);
		if(Frec>Mayor)
			Mayor=Frec;
	}
	
	return Mayor;
}

	
void mostrarVector(array V, int N){
	int i;
	printf("\n V{ ");
	
	for(i=1; i<=N; i++){
		printf("%d, ", V[i]);
	}
	printf("}");
}

void MostrarFrec (array V, int N, int FrecMay){
	int i;
	int Frec;
	
	printf("\nLas notas que mas se repitieron lo hicieron %d veces\n", FrecMay);
	printf("Las notas: \n");
	
	for(i=1; i<=N; i++){
		Frec= Frecuencia(V, N, i);
		if(Frec==FrecMay)
			printf("\t %d", V[i]);
		
	}
	
}

