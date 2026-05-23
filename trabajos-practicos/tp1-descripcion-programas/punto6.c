/*Ejercicio 6: Dados tres números naturales correspondientes a día, mes y año de una fecha, indicar
si dicha fecha es válida.*/
#include <stdio.h>

int main() {
	int a;
	short d, m;
	printf("Ingresa el año: ");
	scanf("%d", &a);
	printf("Ingresa el mes: ");
	scanf("%hd", &m);
	printf("Ingresa el dia: ");
	scanf("%hd", &d);
	
	if(a>0){
		if(m>0 &&m<=12){
			if(d>0){
				switch(m){
				case 4:
				case 6:
				case 9:
				case 11:
					if(d<=30)
						printf("Fecha valida\n");
					else
						printf("Fecha no valida\n");
					break;
				case 2:
					if(a%4==0 && (a%100!= 0 || a%400== 0)){
						if(d<=29)
							printf("Fecha valida\n");
						else
							printf("Fecha no valida\n");
					}
					else{
						if(d<=28)
							printf("Fecha valida\n");
						else
							printf("Fecha no valida\n");
					}
					break;
				default:
					if(d<=31)
						printf("Fecha valida\n");
					else
						printf("Fecha no valida\n");
					break;
				}
			}
			else
			   printf("Fecha no valida\n");
		}
		else
		   printf("Fecha no valida\n");
	}
	else
	   printf("Fecha no valida\n");
	return 0;
}
