#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "TAD_Cliente.h"
#define MAXV 50

typedef RClient Vec[MAXV];
typedef struct{
	Vec V;
	int tam;
}TLista;

TLista CargaLista();
TLista InicializarLis();
void MostrarLista(TLista);
void OrdenQSort(TLista*);
void OrdenMSort(TLista*);
TLista CreaDeudor(TLista);
int BusquedaSec(TLista, TCad);
int BusqBinaria(TLista, long);
void ModificaUno(TLista*, int);
void MuestraUno(TLista*, int);

#endif
