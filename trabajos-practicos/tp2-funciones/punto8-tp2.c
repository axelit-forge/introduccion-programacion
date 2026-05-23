#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNum (unsigned, unsigned);

int main() {
	
	int A, B;
	
	srand(time(NULL));
	do{A=randomNum(0,30);
	B=randomNum(0,30);}while(A==B);
	
	printf("Los numeros turnos son A: %d y B: %d",A,B);
	
	if(A>B) printf("\nEl primer cliente en ser atendido será B");
	else printf("\nEl primer cliente en ser atendido será A");
	
	return 0;
}

int randomNum (unsigned R1, unsigned R2){
	
	return rand() % (R2-R1+1) + R1;
}
