#ifndef TAD_CLIENTE_H
#define TAD_CLIENTE_H
#include "TAD_Cadena.h"

typedef struct{
	TCadena ape, nom;
	long dni;
	float saldo;
}RCliente;

RCliente cargar_cliente();
void mostrar_cliente(RCliente);
void modificar_cliente(RCliente *cliente);
long retornar_DNI(RCliente);
float retornar_saldo(RCliente);
int comparar_DNI(RCliente, long);

#endif
