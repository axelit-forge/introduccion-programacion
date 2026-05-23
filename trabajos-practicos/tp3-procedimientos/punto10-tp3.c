#include <stdio.h>

/*Ejercicio 10: Dada una lista de N fechas ingresadas por el usuario, representadas como números enteros*/
/*	con el formato (AAAADDMM), se pide indicar cuántas fechas son válidas y cuántas no lo son. Se debe*/
/*	tener en cuenta los años bisiestos.*/
/*	Nota: un año será bisiesto si es divisible entre 4, sin embargo, no puede ser divisible entre 100, a menos*/
/*	que también lo sea por 400. Se debe crear un módulo que separe la fecha en día, mes y año.*/

short verif(int, int, int);
void divisionFecha(long, int*, int*, int*);

int main() {
	
	int N, i, B, contador=0;
	int Year, Month, Day;
	long FechaComp;
	
	printf("Ingrese la cantidad de fechas de la lista = "); 
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		
		printf("\nIngrese la fecha: "); scanf("%ld", &FechaComp);
		
		divisionFecha(FechaComp, &Year, &Month, &Day);
		
		B=verif(Year, Month, Day);
		
		if(B==1){
			printf("Fecha: %02d/%02d/%d", Day,Month,Year);
			printf("\t ->VALIDA\n");
			contador++;
		}
		else{
			printf("Fecha: %02d/%02d/%d", Day,Month,Year);
			printf("\t ->NO VALIDA\n");
		}
		
	}
	
	printf("LA CANTIDAD DE FECHAS VALIDAS FUE: %d", contador);
	
	
	return 0;
}

void divisionFecha(long FechaComp, int *aaaa, int*mm, int*dd){
	
	*mm = FechaComp % 100;
	*dd = (FechaComp % 10000) / 100;
	*aaaa = FechaComp / 10000;
	
}

int diames (int m, int ano){
	int dias;
	
	switch(m){
	case 4: case 6: case 9: case 11: dias=30; break;
	case 2: 
		if(ano%4==0) dias=29;
		else 
			dias=28; 
		break;
	default: dias=31;
	}
	return dias;
}

short verif(int ano, int mes, int dia){
	short b=0;
	
	if (ano>1900&&ano<2100)
		if(mes>0 && mes<13)
		if(dia>0 && dia<=diames(mes, ano))
		b=1;
	
	return b;
}
