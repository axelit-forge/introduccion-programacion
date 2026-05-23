#include <stdio.h>
#include "TAD_Lista.h"

void Menu_R(TLista*, TLista*);


int main(void){
	TLista C, D;
	
	C=InicializarLis();
	D=InicializarLis();
	
	C=CargaLista();
	OrdenQSort(&C);
	Menu_R(&C, &D);
	
	
	return 0;
}
void Opciones (){
	printf("\n\tMENU DE OPCIONES: Elija lo que quiera realizar");
	printf("\n [1] Crear y mostrar una lista de deudores ordenada");
	printf("\n [2] Mostrar algun cliente por su nombre y apellido");
	printf("\n [3] Modificar un Cliente segun su DNI");
	printf("\n [4] Mostrar toda la lista de clientes");
	printf("\n [0] Salir del programa \n Opcion elegida: ");
}
void MostrarPorNombre(TLista C){
	TCad Buscado;
	int pos;
	printf("\n Ingrese el nombre y apellido del cliente a buscar: ");
	ScanCad(Buscado);
	pos=BusquedaSec(C, Buscado);
	if(pos!=-1)
		MuestraUno(&C, pos);
	else
		printf("\n Ningun cliente tiene ese nombre y Apellido");
}

void ModificarPorDNI(TLista* C){
	long DNI;
	int pos;
	printf("\n Ingreses el DNI a buscar: ");
	scanf("%ld", &DNI);
	pos=BusqBinaria(*C, DNI);
	if(pos!=-1)
		ModificaUno(C, pos);
	else
		printf("\n No se halló el cliente");
	
}
	
void Menu_R(TLista* C, TLista* D){
	int op;

	Opciones(); scanf("%d", &op);
	
	switch(op){
	case 1: 
		*D=CreaDeudor(*C);
		OrdenMSort(D);
		MostrarLista(*D);
		break;
	case 2:
		MostrarPorNombre(*C);			/*Idem de abajo*/
		break;
	case 3:
		ModificarPorDNI(C);			/*Considere que no eran pertinentes en el TAD asi que los hice usando las funciones del TAD*/
		break;
	case 4:	
		MostrarLista(*C);
		break;
	case 0:
		printf("\n Terminando Programa..."); break;
	default: printf("\n OPCION INVALIDA");	
	}
	
	if(op!=0)
		Menu_R(C, D);
}
