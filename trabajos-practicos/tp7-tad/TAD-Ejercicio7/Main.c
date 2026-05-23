#include <stdio.h>
#include "TAD_Lista.h"

short Menu();

int main (void) {
	TLista Lis;
	short op;
	Lis=CargarLista();
	
	do{
		op=Menu();
		switch(op){
		case 1: AgregarEmpleado(&Lis); break;
		case 2: EliminarEmpleado(&Lis); break;
		case 3: MostrarXTurno(Lis); break;
		case 4: MaxEmpleados(Lis); break;
		case 0: printf("\nSaliendo..."); break;
		default: printf("\n OPCION INVALIDA");
		}
		
	} while(op!= 0);
	
	
	return 0;
};

short Menu(){
	short op;
	
	printf("\n===============================================");
	printf("\nBienvenido/a! Elija lo que quiere realizar");
	printf("\n[1] Agregar un empleado");
	printf("\n[2] Eliminar un empleado");	
	printf("\n[3] Mostrar todos los empleados de un turno");
	printf("\n[4] Mostrar el turno con m�s empleados");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("===============================================\n");
	limpiar_buffer();
	return op;
}
