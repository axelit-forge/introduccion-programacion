#ifndef TAD_LISTA_H
#define TAD_LISTA_H

#include "TAD_Alumno.h"
#define MAXV 30

typedef RAlumno Vec[MAXV];
typedef struct{
	Vec Alumnos;
	int N;
}TLista;

TLista CargarLista();
void MostrarLista(TLista);
void AgregarAlum(TLista*);
void ModEstado(TLista*);
void ModxDNI_Grado(TLista*);
TLista CrearXPostGrado(TLista, Word);

#endif
