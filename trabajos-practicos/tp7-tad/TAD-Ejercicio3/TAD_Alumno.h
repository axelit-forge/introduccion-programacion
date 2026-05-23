#ifndef TAD_ALUMNO_H
#define TAD_ALUMNO_H

#include "TAD_Fecha.h"
#include "TAD_Cadena.h"

typedef enum {
	EnCurso,
	Finalizado,			/*Lo mismo que tener un Estado representado por "int" pero hace que sea más legible el codigo*/
	Pendiente,
	Baja
}Status;

typedef struct{
	long DNI;
	Word ApeNombre;
	Word PostGrado, Grado;
	RFecha Inicio, Fin;
	Status Estado; /*int Estado*/
}RAlumno;

RAlumno CargarAlum();
void MostrarAlum(RAlumno);
void ModificarAlum(RAlumno*);
long GetDNI(RAlumno);
void GetPostGrado(RAlumno, Word);
int CmpNombres(RAlumno, RAlumno);
void ModificarEstado( RAlumno*, RFecha);
int CmpAlumno(RAlumno, Word);


#endif
