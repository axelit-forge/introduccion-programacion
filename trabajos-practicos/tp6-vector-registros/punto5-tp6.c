#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamano 30
/*Ejercicio 5: Se necesita crear un programa que maneje una Agenda telefónica de amigos, que almacena*/
/*	los siguientes datos de cada persona: “Apellidos, Nombres, Dirección, Celular, Fecha de nacimiento”.*/
/*	Realizar un programa que permita cargar la lista de amigos y que la misma se ordene alfabéticamente*/
/*	por Apellidos y Nombres a medida que cargan los registros. Utilizando un menú permita realizar las*/
/*	siguientes operaciones:*/
/*	a) Añadir un nuevo contacto, considerando que cada contacto es único. (Mantener ordenada la lista por*/
/*																		   apellido y nombres).*/
/*	b) Borrar un contacto. (Mantener ordenada la lista por apellido y nombres).*/
/*	c) Dado el apellido y el nombre, modificar su dirección o su teléfono.*/
/*	d) Dado un apellido y el nombre, mostrar sus datos.*/
/*	e) Mostrar la agenda telefónica completa.*/
/*	f) Dado un apellido, mostrar todos los datos de las personas con ese apellido.*/
/*	g) Dado un mes, mostrar todas las personas que cumplen años en ese mes. */
typedef char Word [tamano];
typedef struct{
	int day;
	int month;
	int year;
}Nac;

typedef struct{
	Word Apellidos;
	Word Nombres;
	Word Direccion;
	long Celular;
	Nac Fecha;
}RContacto;

typedef RContacto Agenda[tamano];
/*-*/
Nac CargaFecha ();
void MostraFecha(Nac);

RContacto CargaContacto();
void MostraContacto(RContacto);

void CargarAgenda(int *, Agenda);
void MosstrarAgenda(int, Agenda);

short Menu();
void AgregarContacto(int *, Agenda, Word, Word);
void EliminarContacto(int *, Agenda);
void ModificarContacto(RContacto*);
void MostrarCondicional(int, Agenda);

int main() {
	int N;
	Agenda A;
	
	CargarAgenda(&N, A);
	
/*	do{*/
		
/*	} while();*/
	
	
	
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


Nac CargaFecha (){
	Nac Nvo;
	printf("\nIngrese la fecha:");
	printf("Dia: "); scanf("%d", &Nvo.day);
	printf("Mes: "); scanf("%d", &Nvo.month);
	printf("Año: "); scanf("%d", &Nvo.year);
	return Nvo;
}
void MostraFecha(Nac Nacimiento){
	printf("\nFecha de nacimiento: %d/%d/%d", Nacimiento.year, Nacimiento.month, Nacimiento.day);
}

RContacto CargaContacto(Word VerNombre, Word VerApellido){
	RContacto Nvo;
	int N=tamano;
	
	strcpy(Nvo.Apellidos, VerApellido);
	strcpy(Nvo.Nombres, VerNombre);
	Nvo.Fecha=CargaFecha();
	fflush(stdin);
	printf("Ingrese la dirección: ");
	LeeCad(Nvo.Direccion, N);
	printf("Ingrese el numero de telefono: ");
	scanf("%ld",&Nvo.Celular);
	
	return Nvo;
	
}
void MostraContacto(RContacto A){
	
	printf("Nombre: %s - Apellido %s", A.Nombres, A.Apellidos);
	MostraFecha(A.Fecha);
	printf("Numero: %ld - Dirección %s", A.Celular, A.Direccion);
}

int EstaEnLista(Word Nombre, Word Apellido, int pos, Agenda A){
	int j;
	j=1;
	while (j <= pos && A[j].Nombres!=Nombre)
		j++;
	if(j<=pos)
		return j;
	else
		return -1;
}

	
	
void CargarAgenda(int * N, Agenda A){
	
	Word Nombre, Apellido; int i, Pos;
	i=1;
	printf("\n Ingrese tamano: "); scanf("%d", N);
	
	while(i<= *N){
		printf("\n ingrese Nombre: "); 
		LeeCad(Nombre, 30);
		
		printf("\n ingrese Apellido: ");
		LeeCad(Apellido, 30);
		
		Pos= EstaEnLista(Nombre, Apellido, i, A);
			// AgregarLista(Nombre, Apellido, &i, A);
		 printf("\n El contacto ya está");
	}
	
}

void MosstrarAgenda(int N, Agenda A){
	int i;
	
	if(N>0){
		for(i=1; i<=N; i++) MostraContacto(A[i]);
	}
	else
	   printf("La agenda está vacía");
	
}

void AgregarContacto(int *i, Agenda A, Word Nombre, Word Apellido){
	*i=*i+1;
	A[*i]=CargaContacto(Nombre, Apellido);
}
	
void EliminarContacto(int *, Agenda);
void ModificarContacto(RContacto*);
void MostrarCondicional(int, Agenda);
