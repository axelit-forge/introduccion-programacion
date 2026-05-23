#include <stdio.h>
#include <string.h>
#define tamano 30

typedef char Word [tamano];

typedef struct{
	int Catastro;
	Word Propietario;
	Word CalleNum;
	short Tipo;
	int Metros, Banios, Habit;
}RInmueble;
/*Ejercicio 8: Se tienen la siguiente estructura para un inmueble: N° Catastro, Nombre del Propietario,*/
/*	Calle y N°, Tipo (Terreno, Construcción, Edificado), Metros cuadrados de construcción, Cantidad de*/
/*	baños, Cantidad de habitaciones.*/
/*	Se solicita cargar 3 inmuebles y a través de un menú realizar las siguientes operaciones:*/
/*	a) Mostrar los datos del inmueble con el mayor valor de metros cuadrados de construcción.*/
/*	b) Ingresar un N° de Catastro y permitir modificar la información del registro.*/
/*	c) Dado el Nombre del Propietario mostrar todos los inmuebles declarados. */


int main() {
	
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

RInmueble IngresarInmueble(){
	RInmueble Nvo;
	int N=tamano;
	
	printf("INGRESE UN NUEVO INMUEBLE");
	
	printf("\nCampo- Nombre: ");
	LeeCad(Nvo.Nombre, N);
	printf("\nCampo- Apellido: ");
	LeeCad(Nvo.Apellido, N);
	printf("\nCampo- DNI: "); 
	scanf("%ld", &Nvo.DNI);
	printf("\nCampo- Fecha de Nacimiento: ");
	Nvo.Nac=IngresarFecha();
	printf("\nCampo- Domicilio: ");
	Nvo.Casa=IngresarDomicilio();
	
	return Nvo;
}
