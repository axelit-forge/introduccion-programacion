#include <stdio.h>

#define tamano 30
/*Ejercicio 4: Se tiene una lista de las edades de N alumnos de una escuela, se solicita ingresar la lista*/
/*	y a continuación, mediante un menú:*/
/*	a) Determinar la edad con mayor cantidad de repeticiones, sabiendo que existe y es única.*/
/*	b) Mostrar la primera sublista creciente, de al menos dos números, conformada sólo por elementos pares. */
typedef int array [tamano];

short menu();
void ingresoListaCondicionado (array, int*);
void FrecuenciaMayor(array, int);
void primerSublista (array Vector, int Cantidad);

int main() {
	
	array List;
	int N;
	short Option;
	
	ingresoListaCondicionado(List, &N);
	
	do{
		Option=menu();
		switch(Option){
		case 1: FrecuenciaMayor(List, N);
		break;
		
		case 2: primerSublista (List, N);
		break;
			
		default: printf("\n--NO ES UNA FUNCION--\n");
		}
	}while (Option!=0);
	
	return 0;
}


short menu(){
	short opt;
	
	printf("\n===============================================");
	printf("\n[1] Quiere conocer el elemento de mayor frecuencia");	
	printf("\n[2] Desea Conocer la Primer sublista de edades pares");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &opt);
	printf("===============================================\n");
	
	return opt;
}


void ingresoListaCondicionado (array Vector, int* Cantidad){
	int i;
	
	printf("Ingrese el tamaño de la lista: ");
	scanf("%d", Cantidad);
	
	for (i=1;i<=*Cantidad;i++){
		printf("L[%d] = ", i);
		scanf("%d", &Vector[i]);
	}	
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
	
	
void Max(int Frecuencia, int ElementoVector, int *Mayor, int*Elemento){
	if (Frecuencia> *Mayor){
		*Mayor=Frecuencia;
		*Elemento= ElementoVector;
	}
	
}
	
void FrecuenciaMayor(array Vector, int Cantidad){
	int i, Frec=0, Elemento, Mayor=0;
	
	for (i=1; i<= Cantidad; i++){
		
		Frec= Frecuencia(Vector, Cantidad, i);
		Max(Frec, Vector[i], &Mayor, &Elemento);
	}
	
	printf("El elemento más repetido fue %d, repetido %d vez/veces", Elemento, Mayor);
	
}
	
void primerSublista (array Vector, int Cantidad){
	int i = 1; 
	int B = 0; 
	int Cont = 0;  
	int INI = -1;  
	
	while (i <= Cantidad && B != 1) {  
		if (Vector[i] % 2 == 0) {  
			if (INI == -1) {
				INI = i;  
			}
			Cont++;  
		} else {
			
			if (Cont > 1) {
				B = 1; 
			} else {
				INI = -1;
				Cont = 0;
			}
		}
		i++;  
	}
	if (Cont > 1) {
		printf("Sublista de pares:\n");
		for (int j = INI; j < INI + Cont; j++) {
			printf("V[%d] : %d\n", j, Vector[j]);
		}
	} else {
		printf("No se encontró una sublista de pares.\n");
	}
}
