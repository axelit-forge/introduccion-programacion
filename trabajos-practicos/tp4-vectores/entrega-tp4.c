#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define tamano 30

short menu();
void ingresoListaCondicionado (int[], int*);
void ingresoListaIncondicionado (int [], int*);
void ingresoPila (int [], int*);
int promedioVector (int [], int);
void modificarVector(int [], int, int);
void mostrarVector(int[], int);
/*void ingresoElemento (int [], int*);*/


int main() {
	
	int Vector[tamano], N=0;
	short opt;
	int prom;
	
	do{
		opt=menu();	
	switch (opt) {
	case 1 :
		ingresoListaCondicionado (Vector, &N);
		
		break;
	case 2 :	
		ingresoListaIncondicionado (Vector, &N);
		
		break;
		
	case 3 :
		ingresoPila(Vector, &N);
		
		break;
		
	case 4: 
		mostrarVector(Vector, N);
		
		break;
		
	case 5:
		prom=promedioVector(Vector, N);
		printf("El promedio es %d", prom);
		break;
		
	case 6:
		printf("\n ->EMPIEZA EL PROCESO\n");
		modificarVector(Vector, N, prom);
		
		break;
		
	case 7:
		system ("cls");
		break;
	
	case 0:
		break;
		
	default: printf("INVALIDO");
	}
	}while(opt!=0);
	
	printf ("\n\n\tSALIR PROGRAMA");
	return 0;
}

short menu () {
	
	short op;
	
	printf("\n===============================================");
	printf("\nBienvenido! Elija la forma de cargar el dato");
	printf("\n[1] Conoce el tamaño de la lista");	
	printf("\n[2] No conoce el tamaño de la lista");
	printf("\n[3] Quiere usar una pila");
	printf("\n[4] Mostrar el vector");
	printf("\n[5] Mostrar el promedio");
	printf("\n[6] Modificar el vector");
	printf("\n[7] Si desea borrar la pantalla");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("\n===============================================\n");
	
	return op;
}

void ingresoListaCondicionado (int Vector [], int* Cantidad){

	int i;
	
	printf("Ingrese el tamaño de la lista: ");
	scanf("%d", Cantidad);
	
	for (i=1;i<=*Cantidad;i++){
		printf("V[%d] = ", i);
		scanf("%d", &Vector[i]);
	}
	
}

void ingresoListaIncondicionado (int Vector [], int* Cantidad){
	int i=1;
	
	printf("COLOQUE 0 PARA TERMINAR LA CARGA\n Ingrese el primer elemento: ");
	printf("V[%d] = ", i);
	scanf("%d", &Vector[1]);
	
	while (Vector[i] != 0){
		i++;
		printf("V[%d] = ", i);
		scanf("%d", &Vector[i]);
	}
	*Cantidad = i-1;
}
	
	
void push(int Pila[], int layer, int elemento) {
	int i;
	
	for (i = layer; i > 1; i--) 
	{
		Pila[i] = Pila[i - 1]; 
	}
	Pila[1] = elemento; 
}
	
	
void ingresoPila (int Pila [], int*Layers){
	int i, elemento;
	
	printf("Ingrese el tamaño de la pila: ");
	scanf("%d", Layers);	
	
	
	for (i=1; i<= *Layers; i++) {
		
		printf("\nElemento <%d>= ", i);
		scanf("%d", &elemento);
		push(Pila, i, elemento);
	}
	
}
	
int promedioVector (int Vector [], int Cantidad){
	int i, Acumulador= 0;
	
	for(i=1; i<= Cantidad; i++)
		Acumulador+= Vector[i];
	
	return Acumulador/Cantidad;
}

void modificarVector(int Vector [], int Cantidad, int Promedio){
	int i;
	
	for (i=1; i<= Cantidad; i++){
		if (Promedio< Vector[i])
			Vector[i]= Vector[i]-Promedio;
	}
}
	

void mostrarVector(int V[], int N){
	int i;
	printf("\n V{ ");
	
	for(i=1; i<=N; i++){
		printf("%d, ", V[i]);
	}
	printf("}");
}
	
/*void ingresoElemento (int V[], int *N){*/
/*	int Elemento, Option;*/
	
	
/*	printf("Ingrese el elemento que quiera ingresar: ");*/
/*	scanf("%d", &Elemento);*/
	
/*	do{ printf("\n");*/
/*		printf("\n Elija el ingreso:\n Lista normal (1). \n Por pila (2).\n Opcion: ");*/
/*	scanf("%d", &Option);*/
/*	} while(Option != 1 && Option != 2);*/
	
/*	if(Option==1){*/
/*		V[*N+1]= Elemento;*/
/*		(*N)++;*/
/*	}	*/
/*	else{*/
/*		push(V, *N, Elemento);*/
/*		(*N)++;*/
/*	}*/
/*}*/
