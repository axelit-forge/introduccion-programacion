#include <stdio.h>

int main() {
	
	int basico, tarifa, gastomts, pago;
	
	printf("\n Ingrese la tarifa $: ");
	scanf("%d" , &tarifa);
	
	printf("Ingrese el valor básico $: ");
	scanf("%d" , &basico);
	
	printf("\n Ingrese el consumo a evualar: ");
	scanf("%d" , &gastomts);
	
	printf("\n El gasto de la familia es %d y el total a pagar: ", gastomts);
	if(gastomts<1000){
		pago=basico;}
	
	else if(gastomts>2000){
		gastomts-=1000;	
		pago=basico+gastomts*tarifa;
	}
		else{
			gastomts-=1000;
			pago=basico+gastomts*tarifa*2;
	}
	printf("%d", pago);
	
	return 0;
}

