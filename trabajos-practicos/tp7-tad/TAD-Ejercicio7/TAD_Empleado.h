#ifndef TAD_EMPLEADO_H
#define TAD_EMPLEADO_H

#include "TAD_Cadena.h"

typedef struct{
	long DNI;
	TCad Apellido, Nombre;
	long FecAlta;
	TCad Telefono;
	int Turno;

}REmpleado;

REmpleado CargarEmpleado();
void MostrarEmpleado (REmpleado);
int CmpRegXDNI (REmpleado, long);
int CmpRegXReg (REmpleado, REmpleado);
int CmpTurno (REmpleado, int);
long ReturnDNI(REmpleado);
int ReturnTurn(REmpleado);

#endif
