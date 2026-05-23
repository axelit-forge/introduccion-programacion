#include <stdio.h>

/*Ejercicio 9: Dada una cantidad no determinada de números naturales, para cada número natural primo,*/
/*	calcular su número invertido y para cada número natural no primo (compuesto) modificarlo eliminando*/
/*	todos sus dígitos primos*/
short primo (int);
int invertir (int);
int modificar (int);

int main(int argc, char *argv[]) {
	
	int num;
	short banderaPrimo;
	
	printf("Ingrese un numero natural = "); scanf("%d", &num);
	
	while(num>0){
		
		banderaPrimo=primo(num);
		
		if(banderaPrimo==1){
			num=invertir(num);
			printf("-->Modificacion tipo: <Primo> = %d\n", num);
		}
		else{
		   num=modificar(num);
			printf("-->Modificacion tipo <No primo> = %d\n", num);
		}	
		
		printf("\nIngrese otro numero natural = "); scanf("%d", &num);
	}
	
	return 0;
}

short primo (int X){
	
	int pd, lim;
	
	pd=2; lim=X/2;
	
	while(pd<=lim && X%pd!=0){
		pd++;
	}
	if (pd<lim)
		pd=0;
	else
		pd=1;
	return pd;
}

int invertir (int num){
	int aux;
	aux=0;
	while(num!=0){
		aux=(aux*10)+(num%10);
		num/=10;
	}
	return aux;
}

int modificar (int X){
	
	short d;
	int acu, xcopia;
	int potencia10 = 1;
	
	acu=0;
	xcopia=X;
	
	while (xcopia>0)
	{
		d=xcopia%10;
		
		if(primo(d)==0)
		{
			acu = acu + (d * potencia10);
			potencia10 *= 10;
		}
		
		xcopia/=10;
	}
	
	return acu;
}

