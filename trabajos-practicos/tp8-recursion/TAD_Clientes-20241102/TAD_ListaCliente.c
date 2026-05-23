#include "TAD_ListaCliente.h"

int retorna_tam(TLista L){
	return L.tam;
}
TLista inicializa(){
	TLista aux;
	aux.tam=0;
	return aux;
}
void carga_rec(TVector L, int tam){ /*COMPLETAR*/
	
	if(tam>0){
		carga_rec(L, tam-1);
		printf("\nL[%d]: ", tam);
		L[tam]= cargar_cliente();
	}
	else 
	   printf("\n Lista llena");
}
TLista cargar_clientes(){ 
	TLista L;
	printf("\nIngrese la cantidad de elementos: ");
	scanf("%d", &L.tam);
	carga_rec(L.cli, L.tam);
	return L;
}
int busq_sec_rec(TVector A, int N, long DNI){/*COMPLETAR*/ /*retorna -1 si no lo encuentra sino retorna la posicion*/
	if (N>0)
	{
		if((comparar_DNI(A[N], DNI))==0)
			return N;
		else
			return busq_sec_rec(A, N-1, DNI);
	}
	else
		return -1;
}
void agrega_cliente(TLista *L){ 
	int pos;
	RCliente nvo;
	
	nvo= cargar_cliente();
	pos= busq_sec_rec(L->cli, L->tam, retornar_DNI(nvo));
	if (pos==-1) {
		L->tam++;
		L->cli[L->tam]= nvo;
		printf("\nSe agrego exitosamente el nuevo cliente");
	}
	else printf("\nEl cliente ya esta cargado");
}

void elimina_rec(TVector A, int N, int pos){ /*COMPLETAR*/

}
void elimina_cliente(TLista *A){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del cliente a eliminar: ");
	scanf("%ld", &DNI);
	pos= busq_sec_rec(A->cli, A->tam, DNI);
	if (pos!=-1) {
		elimina_rec(A->cli, A->tam, pos);
		printf("\nSe elimino exitosamente el cliente");
		A->tam--;
	}
	else printf("\nEl cliente no se encuentra");
}
void modifica_cliente(TLista *A){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del cliente a modificar: ");
	scanf("%ld", &DNI);
	pos= busq_sec_rec(A->cli, A->tam, DNI);
	if (pos!=-1) modificar_cliente(&A->cli[pos]);
	else printf("\nEl cliente no se encuentra");
}
void mostrar_rec(TVector A, int tam){ /*COMPLETAR*/

}
void mostrar_clientes(TLista A){
	mostrar_rec(A.cli, A.tam);
}
void genera_rec(TVector A, int N, TVector D, int *M){/*COMPLETAR*/

}
void genera_deudor(TLista A, TLista *D){
	*D=inicializa();
	genera_rec(A.cli, A.tam, D->cli, &D->tam);
}


		
void q_sort(TVector A, int ini, int fin) {/*COMPLETAR*/

}
void ordena_clientes(TLista *D){  
	int ini,fin;
	ini=1;
	fin=D->tam;
	q_sort(D->cli, ini, fin);
}
