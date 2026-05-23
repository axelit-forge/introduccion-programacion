#ifndef TAD_LISTA_H
#define TAD_LISTA_H

#include "TAD_Empleado.h"
#define MAXV 30

typedef REmpleado Vec[MAXV];
typedef struct{
	Vec Empleados;
	int N;
}TLista;

TLista CargarLista();
void OrdenBurb(TLista*);
void AgregarEmpleado(TLista*);
void EliminarEmpleado(TLista*);
void MaxEmpleados(TLista);
void MostrarXTurno(TLista);


#endif
