#ifndef TAD_CLIENTE_H
#define TAD_CLIENTE_H
#include "TAD_Cadena.h"

typedef struct{
	TCad NomYApe;
	long DNI;
	float Saldo;
}RClient;

RClient CargaUno();
void MostrarCliente(RClient);
void Modificar(RClient*);
int CmpClient(RClient, RClient, int);		/*Hace una comparacion según el int que se mande, 1 para NombreApe/ 2 para DNI / 3 para Saldo*/
int EsDeudor(RClient);
void GetNombre(RClient, TCad);
long GetDNI(RClient);


#endif
