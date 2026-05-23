#include "TAD_ListaPacientes.h"
#include <stdio.h>			

/*COMPLETAR*/																	/*Faltaba el stdio*/

TLista inicializa_lista(){
	TLista aux;
	aux.tam=0;
	return aux;
}

void cargaVectorRecursiva(TVector V,int tam){
	if(tam>0){														/*el error era que el if no estaba bien cerrado*/
		cargaVectorRecursiva(V,tam-1);
		printf("\n Ingrese Paciente [%d] : ",tam);
		V[tam]=cargar_paciente();
	}
}
	
void cargaVector(TVector V,int *tam){
	printf("\n Ingrese Tamaño de la lista : "); scanf("%d",tam);
	printf("\n Ingrese Lista : ");
	cargaVectorRecursiva(V,*tam);
}
	
TLista carga_pacientes(){
	TLista aux;
	aux=inicializa_lista();
	cargaVector(aux.lis,&aux.tam);
	return aux;
}
	
int retorna_tam(TLista aux){
	return aux.tam;
}
	
void agrega_elemento(TVector V, int *tam){
	*tam=*tam+1;
	V[*tam]=cargar_paciente();
}
	
void agrega_pacientes(TLista *aux){
	agrega_elemento(aux->lis,&aux->tam);
}
	
int bus_sec_rec(TVector V, int tam, int bus){
	if(tam>0){
		if(compara_DNI(V[tam],bus)!=1)
			return bus_sec_rec(V,tam-1,bus);
		else
			return tam;
	}
	else
	   return -1;
}
	
void EliminaRec(TVector V, int tam, int pos){
	if(pos<=tam){
		V[pos]=V[pos+1];
		EliminaRec(V,tam,pos+1);
	}
}
	
void elimina_pacientes(TLista *aux){
	int pos;
	long DNI;
	printf("\n Ingrese DNI: ");
	scanf("%ld",&DNI);
	pos=bus_sec_rec(aux->lis,aux->tam,DNI);
	if(pos!=-1){
		EliminaRec(aux->lis,aux->tam,pos);
		aux->tam--;
		printf("\n-Se elimino correctamente.\n");
	}
	else
		printf("\n No se encuentra en la lista.\n");
}

void modifica_pacientes(TLista *aux){
	int pos;
	long DNI;
	printf("\n Ingrese DNI: ");
	scanf("%ld",&DNI);
	pos=bus_sec_rec(aux->lis,aux->tam,DNI);
	if(pos!=-1)
		modificar_paciente(&aux->lis[pos]);								/*el de pos estaba pasado por valor(por mas que el registro esté por ref, tenes que poner & para pasar por ref el elemento*/
	else
	   printf("\n No se encuentra en la lista.\n");
}
	
void MostrarVectorRec(TVector V, int tam){
	if(tam>0){
		MostrarVectorRec(V,tam-1);
		mostrar_paciente(V[tam]);
	}
}
	
void mostra_pacientes(TLista aux){
	MostrarVectorRec(aux.lis,aux.tam);
}
	
void GenerarListaRec(TVector V, int tam, TVector U, int *tamNvo, int tipo, long fecha){
	if(tam>0){
		GenerarListaRec(V,tam-1,U,tamNvo, tipo, fecha);								/*faltaban argumentos(tipo y fecha)*/
		if(compara_fecha_tipo(V[tam],fecha,tipo)==1){
			*tamNvo=*tamNvo+1;
			U[*tamNvo]=V[tam];
		}
	}
}

void genera_atencion(TLista aux1, TLista *aux2){
	int tipo;
	long fecha;
	printf("\n-Ingrese Tipo de Atencion(1: Clinica, 2: Odontologia o 3: Traumatologia): ");
	scanf("%d",&tipo);
	printf("\n-Ingrese una Fecha de Atenciion: ");
	scanf("%ld",&fecha);
	*aux2=inicializa_lista();
	GenerarListaRec(aux1.lis,aux1.tam,aux2->lis,&aux2->tam,tipo,fecha);
}
	
void Q_Sort(TVector V, int ini, int fin){
	int med,izq,der;
	RPaciente piv;
	if(ini<fin){
		piv=V[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(der>izq && compara_apellidos(V[der],piv)==1)
				der--;
			if(der>=izq){
				V[izq]=V[der];
				izq++;
			}
			while(izq<der && compara_apellidos(V[izq],piv)==-1)
			   izq++;
			if(izq<der){
				V[der]=V[izq];
				der--;
			}
		}
		V[der]=piv;
		med=der;
		Q_Sort(V,ini,med-1);
		Q_Sort(V,med+1,fin);
	}
}
	
void ordena_pacientes(TLista *aux){
	Q_Sort(aux->lis,1,aux->tam);
}

int ContarPorFechas(TVector V, int tam, long A, long B){
	if(tam>0){
		if(EnIntervalo(V[tam], A, B)==1)
			return 1 + ContarPorFechas(V, tam-1, A, B);
		
		return ContarPorFechas(V, tam-1, A, B);
	}
	return 0;
}
	
	
int cantidad_pacientes(TLista aux){
	int cant;
	long f1,f2;
	printf("\n Ingrese el intervalo de fechas: ");
	printf("\n Fecha A: "); scanf("%ld", &f1);
	printf("\n Fecha B: "); scanf("%ld", &f2);
	cant=ContarPorFechas(aux.lis,aux.tam,f1,f2);
	return cant;
}
