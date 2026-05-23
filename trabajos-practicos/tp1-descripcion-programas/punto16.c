#include <stdio.h>

/*Ejercicio 16: Dado un número natural K de dos cifras, se pide mostrar los números naturales primos
que le anteceden. Por ejemplo, si K= 12 la salida será {2, 3, 5, 7, 11).*/

int main() {
	
	int K, i, pd;
	
	do{printf("\n Ingrese un valor K: ");
	scanf("%d" , &K);} while(K<10);
	
	for(i=1;i<=K;i++){
		pd=2;
		while(pd<=i/2&&i%pd!=0)
			pd++;
		if(pd>i/2&&i!=1)
			printf("- %d ", i);
	}
	return 0;
}

