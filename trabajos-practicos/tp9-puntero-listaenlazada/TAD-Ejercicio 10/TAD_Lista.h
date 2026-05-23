#ifndef TAD_LISTA_H
#define TAD_LISTA_H

#include "TAD_Song.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	Song Data;
	struct Nodo* Next;
}tNodo;

typedef tNodo* tLista;

tLista Inicializar();
tLista CargarLista(int);
void MostrarLista(tLista);
void AgregarUno(tLista*);
void MostrarFrec(tLista);
void MostrarCondicionado(tLista, int); 			/*Usamos 1 para nombre, 2 Interprete(Artista), 3 Album */
void FreeLista(tLista*);


#endif
