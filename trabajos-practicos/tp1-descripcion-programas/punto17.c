#include <stdio.h>

/*Dada una lista de números naturales, se pide contabilizar cuántos de ellos son
capicúas e indicar los capicúas que están formados sólo por dígitos impares.*/

int main() {
	
	short dig=0, b, contador=0;			/*Declaracion de variables*/
	int num;
	unsigned aux=1, cap;
	
	
	printf("\nIngrese un número: ");		/*Ingreso condicionado*/
	scanf("%d", &num);
	
	while(num>0) { 			/*Componente de capicua*/
		
		cap=0;
		b=0;		/*Bandera que de no activarse quiere decir que todos los digitos son impares*/
		aux=num;
		
		while(aux!=0){	/*Componente capicua*/
			dig=aux%10;
			if(dig%2==0)	/*Con un solo digito par la bandera cambiará */
				b=1;
			cap=cap*10+dig;
			aux/=10;
		}
		if (cap==num){	/*Verificacion del componente y uso de la bandera*/
			contador++;
			if (b==0)
				printf("\n %d es capicúa formado solo por impares", num);}
		
		printf("\nIngrese un número: ");
		scanf("%d", &num);			/*Entradaa de más num (ciclo condicionado)*/
	}	
	if (contador==0)	/*Verificacion de la codicion*/
		printf("\n No hubo ningún capicua");
	else
		printf("\n La cantidad de capicuas ingresados fueron: %hd", contador);
		
	
	
	return 0;
}

