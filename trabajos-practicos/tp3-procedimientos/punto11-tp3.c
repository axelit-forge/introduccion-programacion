#include <stdio.h>

/*Ejercicio 11: Una persona que requiere registrarse en una app, debe elegir una contraseña de 6 dígitos,*/
/*	todos distintos. Si el usuario ingresa un número con cifras repetidas, la app le advierte el error y le sugiere*/
/*	una nueva clave, compuesta por las cifras no repetidas del número ingresado, a la que le agregan nuevos*/
/*	dígitos sin repetir. Los dígitos se agregan siempre como cifra menos significativa. Diseñe e implemente*/
/*	un programa modular, que reciba un número entero y lo modifique de acuerdo al criterio explicado*/
/*	anteriormente. */
int invertir (int);
short verif (int, int);
void modificar (int*, int*);

int main() {
	
	int Contrasena, ContrasenaY=0;
	int i, Acu=0;
	
	printf("Ingrese la contraseña: "); scanf("%d", &Contrasena);
	
	Contrasena=invertir(Contrasena);
	ContrasenaY=Contrasena;
	
	while (ContrasenaY>0){
		modificar(&ContrasenaY, &Acu);
	}
	
	i=0;
	while (i < 10 && Acu/100000==0) {
		if (!verif(Acu, i)) { 
			Acu = Acu * 10 + i; 
		}
		i++;
	}
	
	printf("\n La nueva contraseña es: %d", Acu);
	
	return 0;
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
	
void modificar (int* X, int*Acu){
	
	int exponente10=1;
	int dig, copia=0, comparacion;
	
	comparacion= *X%10;
	*Acu = *Acu*10 + comparacion;
	*X = *X/10;
	
	while (*X>0){
		
		dig= *X % 10;
		if (dig!=comparacion){
			copia= copia + dig*exponente10;
			exponente10*=10;
		}
		
		*X=*X/10;
	}
	*X=copia;
}


short verif (int num, int digProbar){
	int aux; 
	short b=0;
	aux=0;
	while(num!=0 && b==0){
		aux=(aux*10)+(num%10);
		if (digProbar==num%10)
			b=1;
		num/=10;
	}
	return b;
}	
