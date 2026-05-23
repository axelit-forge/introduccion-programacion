#include <stdio.h>

#define tamano 50

/*Ejercicio 7: Dada una lista A de M caracteres alfanuméricos todos distintos y un carácter X ingresado*/
/*	por teclado, se solicita informar si dicho carácter se encuentra en la lista A ingresada y en cual*/
/*	posición. Considerar los siguientes casos*/
/*	a) La lista A no está ordenada.*/
/*	b) Ordenar la lista A, previamente a determinar la posición de los elementos.*/
	
typedef char phrase [tamano];

void ingresoListaIncondicionada (phrase,int*);
short menu();
void busquedaSecuencial(phrase, int);
void ordenarBaraja (phrase, int);
void busquedaBinaria (phrase, int);

int main() {
	phrase List;
	int M;
	short Option;
	
	ingresoListaIncondicionada(List, &M);
	
	do{
		Option=menu();
		switch(Option){
		case 1: 
			fflush(stdin);
			busquedaSecuencial(List, M);
		break;
		
		case 2: 
			fflush(stdin);
			ordenarBaraja(List, M);
			busquedaBinaria(List, M);
		break;
		
		default: printf("\n--NO ES UNA FUNCION--\n");
		}
	}while (Option!=0);
	
	return 0;
}

void ingresoListaIncondicionada (phrase F, int*Cantidad){
	int i;
	
	printf("Ingrese la cantidad de caracteres de la lista: ");
	scanf("%d%*c", Cantidad);
	
	for(i=1 ;i <= *Cantidad ; i++){
		printf("F[%d] = ", i);
		scanf("%c%*c", &F[i]);
	}	
}

short menu(){
	short opt;
	
	printf("\n===============================================");
	printf("\n[1] Encontrar X sin ordenar lista");	
	printf("\n[2] Encontrar X despues de ordenar la lista");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &opt);
	printf("===============================================\n");
	
	return opt;
}


void busquedaSecuencial (phrase F, int N){
	int i=1;
	char elemento;
	
	printf("Ingrese un elemento: ");
	scanf("%c", &elemento);
	
	while (i<=N && F[i] != elemento)
		i++;
	if (i>N)
		printf("ERROR: No se encontró");
	else
		printf("La posicion del elemento es %d", i);
}
	
void ordenarBaraja (phrase F, int M){
	int i, j;
	
	for(i=1; i<=M; i++){
		
		F[0]=F[i];
		j= i-1;
		
		while(F[j] > F[0]){
			F[j+1]=F[j];
			j--;
		}
		F[j+1]= F[0];
	}
}

void busquedaBinaria (phrase F, int M){
	int ini, fin, med;
	char elemento;
	ini=1;
	fin=M;
	med=(ini+fin)/2; 
	
	printf("Ingrese un elemento: ");
	scanf(" %c", &elemento);
	
	while(ini<=fin && elemento!=F[med]){
		if(elemento<med)
			fin=med-1;
		else
			ini=med+1;
		med= (ini+fin)/2;
	}
	if(ini>fin)
		printf("ERROR: No se encontró");
	else
		printf("La posicion del elemento es %d", med);
	
}
