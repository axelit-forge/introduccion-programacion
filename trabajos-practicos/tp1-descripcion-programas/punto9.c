#include <stdio.h>

/*Ejercicio 9*/
	
int main(){
	
	/*Definicion de variables*/
	short veh, HoraE, HoraS, MinutosE, MinutosS, HoraTotal;
	int tarifa, pago;
	
	printf("\n Ingrese la tarifa($) por hora: ");
	scanf("%d" , &tarifa);
	
	printf("Indique que tipo de vehiculo es: motocicleta(1), Auto(2), Camioneta(3): ");
	scanf("%hd" , &veh);
	
	do{	do{printf("\nIndique el horaro de entrada");
		printf("\nHora: ");
		scanf("%hd" , &HoraE);
		printf("Minutos: ");
		scanf("%hd" , &MinutosE);}while(HoraE<0||HoraE>24||MinutosE>60||MinutosE<0);
		
		printf("\nIndique el horaro de salida");
		do{printf("\nHora: ");
		scanf("%hd" , &HoraS);
		printf("Minutos: ");
		scanf("%hd" , &MinutosS);}while(HoraS<0||HoraS>24||MinutosS>60||MinutosS<0);
	}while(HoraE>HoraS);
	
	HoraTotal=HoraS-HoraE;
	MinutosS-=MinutosE;
	if(MinutosS>5)
		HoraTotal++;
	pago=tarifa*veh*HoraTotal;
	
	printf("\nEl total a pagar es: %d", pago);
	
	
	return 0;
}

