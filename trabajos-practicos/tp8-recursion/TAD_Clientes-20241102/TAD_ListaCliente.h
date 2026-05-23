#ifndef TAD_LISTACLIENTE_H
#define TAD_LISTACLIENTE_H
#include "TAD_Cliente.h"

typedef RCliente TVector [10];
typedef struct{
	TVector cli;
	int tam;
} TLista;

TLista inicializa();
TLista cargar_clientes();
void agrega_cliente(TLista *);
void elimina_cliente(TLista *);
void modifica_cliente(TLista *);
void mostrar_clientes(TLista );
void genera_deudor(TLista, TLista *);
void ordena_clientes(TLista *);
int retorna_tam(TLista);

#endif
