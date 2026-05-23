#include <stdio.h>

/*Ejercicio 12: Dada una lista con las edades de N deportistas, se necesita informar la edad promedio
de los deportistas de la lista; cuál es la menor y mayor edad ingresada.*/

int main() {
	
	/*Def de variables*/
	int edad, i, cantidad, suma=0;
	int promedio=0, menor=0, mayor=0;
	
	/*Entrada de valores*/
	printf("\n Ingrese la cantidad de atletas: ");
	scanf("%d" , &cantidad);
	
	for(i=1;i<=cantidad;i++){
		printf("\n Ingrese la edad de un atleta: ");	/*Entrada de edades y la suma para luego sacar promedio*/
		scanf("%d" , &edad);
		suma+=edad;
		
		if(i==1){mayor=edad; menor=edad;}	/*For usando el I=1 como bandera, con componente mayor y menor*/
		else if(edad>mayor)
		   mayor=edad;
		else if(edad<menor)
			menor=edad;
	}
	
	promedio=suma/cantidad;		/*fin del componente promedio*/
	
	printf("\n La edad promedio de los atletas es de: %d, la edad mayor es %d y la menor %d", promedio, mayor, menor);
		
	return 0;
}

