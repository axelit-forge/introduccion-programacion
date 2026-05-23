#include "TAD_Cliente.h"
#include <stdio.h>

RClient CargaUno(){
	RClient Nvo;
	
	printf("\n-----------------------------");
	printf("\n Nuevo Cliente:\n");
	printf("\n Nombre y apellido: "); ScanCad(Nvo.NomYApe);
	printf(" DNI: "); scanf("%ld", & Nvo.DNI);
	printf(" Saldo: "); scanf("%f", & Nvo.Saldo);
	
	return Nvo;
}
void MostrarCliente(RClient C){
	printf("\n Nombre y apellido: "); PrintCad(C.NomYApe);
	printf("\n DNI: %ld, \t Saldo: $%.2f", C.DNI, C.Saldo);
	printf("\n ");
}
void Modificar(RClient* C){
	RClient Aux;
	int opt= -1;
	
	printf("\n Cliente actual: "); 
	MostrarCliente(*C);
	do{
		Aux=CargaUno();
		printf("\n ¿Desea guardar cambios? (1: Si // 0: No // 2: Deseo cambiar algo mas): ");
		scanf("%d", &opt);
	} while(opt!=0 && opt!=1);
	
	if (opt == 1) {
		*C = Aux;
		printf("\n Cambios guardados exitosamente.");
	} 
	else 
		printf("\n No se realizaron cambios.");
}
int CmpClient(RClient A, RClient B, int op){
	int Resp;
	
	switch(op){
	case 1:
		Resp= CmpCad(A.NomYApe, B.NomYApe); break;
	case 2:
		Resp= ( (A.DNI>B.DNI) - (A.DNI<B.DNI) ); break;
	case 3:
		Resp= ( (A.Saldo>B.Saldo) - (A.Saldo<B.Saldo) ); break;
	}
	
	return Resp;
}
int EsDeudor(RClient A){
	if (A.Saldo<0)
		return 1;
	return 0;
}
	
void GetNombre(RClient A, TCad Aux){
	CpyCad(Aux, A.NomYApe);
}
long GetDNI(RClient A){
	return A.DNI;
}
