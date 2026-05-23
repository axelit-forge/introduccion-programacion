#include <stdio.h>


int main (void){
	
	/*Definicion de variables*/
	int a,b,x,i;
	int n, lista_b=0, lista_a=0;
	
	/*Ingreso de variables*/
	printf("\nIngrese el valor A:");
	scanf("%d",&a);
	printf("\nIngrese el valor B:");
	scanf("%d",&b);
	
	printf("\nIngrese la cantidad de numeros a analizar: ");
	scanf("%d",&n);
	
	/*Ciclo Para, para verificar*/
	for(i=1;i<=n;i++){
		printf("\nIngrese el valor X:");
		scanf("%d",&x);
		
		if(x%a==0&& x%b!=0)
			lista_a++;
		
		else if(x%b==0&&x%a!=0)
			lista_b++;
	}
	
	/*Salida y verificacion*/
	if(lista_a==0&&lista_b==0)
		printf("\nNingun X cumple");
	else
		printf("\nLos X multiplos solos de A son: %d y los X multiplos solos de B son: %d", lista_a, lista_b);
	
	return 0;
}
