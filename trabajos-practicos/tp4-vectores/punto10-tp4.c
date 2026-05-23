#include <stdio.h>
#include <stdlib.h>

#define tamano 30

typedef int list [tamano];

/*Ejercicio 10: Una entrenadora de ciclismo lleva una lista con información de N entrenamientos*/
/*	realizados por un ciclista. Para cada entrenamiento se tiene la siguiente información: la Velocidad del*/
/*	ciclista, el Tiempo transcurrido (en segundos), La fecha de realización (Dia/Mes/Año), y un Número de*/
/*	identificación para cada sesión. Se solicita ingresar la lista de entrenamientos y, dado un valor de*/
/*	velocidad V, determinar cuántos entrenamientos presentan un valor mayor al ingresado. Calcular el*/
/*	promedio de las velocidades de los entrenamientos, Además, dado un tiempo T, mostrar las actividades*/
/*	cuyo tiempo se encuentren en el intervalo [T-30 segundos y T+30 segundos]. */
void ingresoListaIncondicionada (list, list, list, list, int*);
void mayorVelocidad(list, int);
void promedioVelocidad (list , int);
void mostrarCondicional (list , list , list , list , int );
	
int main() {
	
	list Velocidad, Time, Fecha, numeroID;
	int N;
	
	ingresoListaIncondicionada(Velocidad, Time, Fecha, numeroID, &N);
	
	mayorVelocidad(Velocidad, N);
	
	promedioVelocidad(Velocidad, N);
	
	mostrarCondicional( Velocidad,  Time,  Fecha,  numeroID, N);
	
	return 0;
}

void ingresoListaIncondicionada (list Velocidad, list Tiempo, list Fecha, list numeroID, int*Cantidad){
	int i;
	
	printf("Ingrese entrenamientos: ");
	scanf("%d", Cantidad);
	fflush(stdin);
	
	for(i=1 ;i <= *Cantidad ; i++){
		printf("Ingrese los datos del entrenamiento n° [%d]: \n", i);
		
		printf("Velocidad (en Mts/min): ");
		scanf("%d", &Velocidad[i]);
		
		printf("Tiempo transcurrido, en segundos: ");
		scanf("%d", &Tiempo[i]);
		
		printf("Fecha de inicio: ");
		scanf("%d", &Fecha[i]);
		
		printf("Numero de ID: ");
		scanf("%d", &numeroID[i]);
	}	
}

	
void mayorVelocidad(list Velocidad, int N){
	
	int AComparar;
	int cont=0, i;
	
	printf("\n ingrese la velocidad a comparar: ");
	scanf("%d", &AComparar);
	
	for (i=1;i<=N;i++){
		if (Velocidad[i]>AComparar)
			cont++;
	}
	
	printf("\n La cantidad de entrenamientos con mayor velocidad que el ingresado son %d", cont);
}	
	
	
void promedioVelocidad(list Velocidad, int N){
	
	int prom=0;
	int i;
	
	for(i=1; i<=N; i++){
		prom+= Velocidad[i];
	}
	
	prom/=N;
	
	printf("\n El promedio de velocidades sde los sentrenamientos es %d", prom);
}
	
void mostrarCondicional (list Velocidad, list Tiempo, list Fecha, list numeroID, int Cantidad){
	int i;
	int T, a, b;
	printf("\nIngrese T, para formar el rango; ");
	scanf("%d", &T);
	
	a=T-30; b=T+30;
	printf("\nEl intervalo a trabajar es [%d, %d]", a, b);
	
	for(i=1; i<= Cantidad; i++){
		if(Tiempo[i]>=a && Tiempo[i]<=b)
			printf("\nID: %d - Velocidad: %d - Tiempo: %d - Fecha: %d", numeroID[i], Velocidad[i], Tiempo[i], Fecha[i]);
	}
	
	
}
