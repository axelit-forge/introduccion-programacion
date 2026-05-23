#include <stdio.h>

short menu ();
long invertir (long);
void codificar (long *);
void decodificar (long*);

int main() {
	
	short b, bandera;
	long mensaje;
	
	b=menu();
	
	if (b==1){
		printf("Ingrese el mensaje para codificar: "); scanf("%ld", &mensaje);
		if(mensaje%10==0) bandera=1;
		
		codificar(&mensaje);
		mensaje=invertir(mensaje);
		
		if(bandera==1) {mensaje*=10;}
		
		printf("El mensaje codificador es: %ld", mensaje);
	}
	else{ 
		printf("Ingrese el mensaje a decodificar: "); scanf("%ld", &mensaje);
		
		mensaje=invertir(mensaje);
		decodificar(&mensaje);
		
		printf("El mensaje decodificado es: %ld", mensaje);
	}
	
	
	
	return 0;
}

short menu () {
	
	short op;
	
	do{printf("\n===============================================");
	printf("\nBienvenido, elija la opcion que desee realizar:");
	printf("\n[1] Enviar un mensaje");	
	printf("\n[2] Decodificar un mensaje");
	printf("\n[0] Salir ");
	printf("\nOpcion: "); 	scanf("%hd", &op);
	printf("\n===============================================\n");}while(op>2||op<0); 
	
	return op;
}



void codificar (long * X){
	
	int d, contador=0;
	long acumulador=0;
	
	
	while (*X>0){
		d = *X%10;
		*X/=10;
		contador=1;
		
		while(d== *X%10 && *X>0) {
			contador++;
			*X/=10;
		}
		acumulador= acumulador*10 + d;
		acumulador= acumulador*10 + contador;
		
		
	}
	
	*X=acumulador;
	
}
	
long invertir (long num){
	long aux;
	aux=0;
	while(num!=0){
		aux=(aux*10)+(num%10);
		num/=10;
	}
	return aux;
}	

void decodificar (long* X){
	int d, contador;
	long acumulador=0;
	
	while (*X>0){
		contador= *X%10;
		
		*X/=10;
		d= *X%10;
		
		*X/=10;
		
		while (contador>0){
			acumulador= acumulador*10 + d;
			contador--;
		}
	}
	*X=acumulador;
	
}
	

