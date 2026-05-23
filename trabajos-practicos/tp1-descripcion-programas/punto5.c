#include <stdio.h>

int main(void) { 
	
	int segundos_totales, horas, minutos, segundos;
	
	printf("\nIngrese la cantidad de segundos a transformar: ");
	scanf("%d", &segundos_totales);
	
	horas = segundos_totales /3600;
	minutos = segundos_totales%3600/60;
	segundos = segundos_totales%60;
	
	printf("\nLa cantidad de horas: %d -minutos: %d - segundos: %d", horas, minutos, segundos);
	
	return 0;
}
