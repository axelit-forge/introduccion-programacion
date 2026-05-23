#include <stdio.h>

int main() {
	
	short Altura1,Altura2,Altura3;
	short prom;
	
	do{printf("Ingrese la primer altura: ");
	scanf("%hd" , &Altura1);}while(Altura1>250||Altura1<100);
	
	do{printf("Ingrese la segunda altura en cm: ");
	scanf("%hd" , &Altura2);}while(Altura2>250||Altura2<100);
	
	do{printf("Ingrese la tercer altura: ");
	scanf("%hd" , &Altura3);}while(Altura3>250||Altura3<100);
	
	prom=(Altura1+Altura2+Altura3)/3;
	
	printf("\nEl promedio de altura de los 3 atletas es %hd", prom);
	
	
	return 0;
}

