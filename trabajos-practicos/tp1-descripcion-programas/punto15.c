#include <stdio.h>
#include <stdlib.h>

/*Ejercicio 15: Dada una lista de N números, se desea obtener el promedio de los números que estén formados únicamente con dígitos pares.
a. Considerar que la lista es de números enteros.
b. Considerar que la lista es de números reales positivos.*/

int main() {
	
	int n, num, sum, cant;
	int i, dig, aux, prom;
	short b=0;
	
	printf("\nIngrese la cantidad de datos: ");		/*Ingreso incondicionado*/
	scanf("%d", &n);
	
	sum=0;
	cant=0;
	
	for(i=1;i<=n;i++){
		
		printf("\nIngrese un número: ");		/*Ingreso incondicionado*/
		scanf("%d", &num);
		
		aux=abs(num);
		
		b=0;
		while(aux!=0){		/*Variante de Sep de Digito*/
			dig=aux%10;
			if(dig%2!=0)
				b=1;
			aux/=10;
		}	
		if(b==0){
			sum+=num;
			cant++;
		}
	}
	if(cant==0)
		printf("\nningun complió");
	else{ 
		prom=sum/cant;
		printf("\nEl promedio de los numeros formados solo por pares es %d", prom);
	}

	
	
	return 0;
}

