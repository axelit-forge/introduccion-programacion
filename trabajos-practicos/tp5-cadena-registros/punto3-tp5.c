#include <stdio.h>
#define tamano 30

typedef char Word [tamano];

void LeeCad (Word, int);

int main() {
	Word Apellido, Nombre;
	long DNI, FechaNac;
	int N=tamano;
	
	printf("Ingrse los datos del alumno: ");
	
	printf("\nNombre: ");
	LeeCad(Nombre, N);
	printf("\nApellido: ");
	LeeCad(Apellido, N);

	printf("Ingrese la Fecha de nacimiento: "); scanf("%ld", &FechaNac);
	printf("Ingrese el DNI: "); scanf("%ld", &DNI);
	
	
/*	mostrad*/
	printf("Los datos ingresados son:");
	printf("\nNombre: %s, Apellido: %s", Nombre, Apellido);
	printf("\nDNI: %ld, Fecha de nacimiento: %ld", DNI, FechaNac);
	
	return 0;
}

void LeeCad (Word A, int tam){
	int j=0; char c;
	c=getchar();
	
	while(c!=EOF && c!= '\n' && j<tam){
		A[j]=c;
		j++;
		c=getchar();
	}
	A[j]= '\0';
	while(c!=EOF && c!='\n')
		c= getchar();
}
