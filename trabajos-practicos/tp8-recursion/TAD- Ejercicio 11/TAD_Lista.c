#include "TAD_Lista.h"
#include <stdio.h>


void CargaVec_R(Vec V, int N){								/*privada*/
	if(N!=0){
		CargaVec_R(V, N-1);
		printf("\n Cliente[%d]", N);
		V[N]=CargaUno();
	}
};

TLista CargaLista(){
	TLista Nvo;
	printf("\n Ingrese la Cantidad de clientes de la lista: ");
	scanf("%d", & Nvo.tam);
	
	CargaVec_R(Nvo.V, Nvo.tam);
	
	return Nvo;
}
TLista InicializarLis(){
	TLista Ini;
	Ini.tam=0;
	return Ini;
}
	
void MostrarRecursivo(Vec V, int N){				/*privada*/
	if(N!=0){
		MostrarRecursivo(V, N-1);
		printf("\n Cliente[%d]", N);
		MostrarCliente(V[N]);
	}
}
	
void MostrarLista(TLista L){
	printf("\n-------------LISTA---------------\n");
	MostrarRecursivo(L.V, L.tam);
	printf("\n---------------------------------\n");
}
	
void Q_sort(Vec L, int ini, int fin){
	RClient piv; 
	int izq, der, med;
	
	if (ini<fin){
		piv=L[ini];
		izq=ini;
		der=fin;
		while (izq<der){
			while (der>izq && (CmpClient(L[der], piv, 2)==1))
				der--;
			if (der>izq){
				L[izq]=L[der];
				izq++;
			}
			while (izq<der && (CmpClient(L[izq], piv, 2)== -1))
				izq++;
			if (izq<der){
				L[der]=L[izq];
				der--;
			}
		}
		L[der]=piv; 
		med=der;
		Q_sort(L,ini,med-1);
		Q_sort(L,med+1,fin);
	 }
}
	
void OrdenQSort(TLista* L){
	
	Q_sort(L->V, 1, L->tam);
}
	
void merge(Vec L,int ini, int m, int fin){
	Vec aux; 
	int i,j,k,t;
	k=0;
	i=ini;
	j=m+1;
	while (i<=m && j<=fin){
		k++;
		if (CmpClient(L[i],L[j],3)==-1){
			aux[k]=L[i];
			i++;
		}
		else{
			aux[k]=L[j];
			j++;
		}
	}
	for(t=i;t<=m;t++){
		k++;
		aux[k]=L[t];
	}
	for(t=j;t<=fin;t++){
		k++;
		aux[k]=L[t];
	}
	for(t=1;t<=k;t++) 
		L[ini+t-1]=aux[t];
}

void MergeSort(Vec L, int ini, int fin){
	int m;
	if(ini<fin){
	m= (ini+fin)/2;
	MergeSort(L, ini, m);
	MergeSort(L, m+1, fin);
	merge(L, ini, m, fin);
	}
}
	
void OrdenMSort(TLista* L){
	MergeSort(L->V, 1, L->tam);
}

void creaVec(Vec D, int* n, Vec A, int m){			/*privada*/
	if(m!=0){
		if(EsDeudor(A[m])==1){
			*n=*n+1;
			D[*n]= A[m];
			creaVec(D, n, A, m-1);
		}
		else
		   creaVec(D, n, A, m-1);
	}
}

TLista CreaDeudor(TLista L){
	TLista Deudor;
	Deudor.tam=0;
	creaVec(Deudor.V, &Deudor.tam, L.V, L.tam);
	return Deudor;
}
	
int Secuencial_R(Vec V, int N, TCad F){				/*privada*/
	TCad Aux;
	GetNombre(V[N], Aux);
	if(N!=0){
		if(CmpCad(Aux, F)==0)
			return N;
		else
			return Secuencial_R(V, N-1, F);
	}
	else
	   return -1;
}
	
int BusquedaSec(TLista L, TCad F){
	return Secuencial_R(L.V, L.tam, F);
}
	
int Binaria_R(Vec V, int Ini, int Fin, long bus){		/*privada*/
	int Med;
	long Comp;
	Med=(Ini+Fin)/2;
	Comp=GetDNI(V[Med]);
	if( Ini<=Fin){
		if(bus==Comp) return Med;
		else{
			if(bus>Comp)
				return Binaria_R(V, Med+1, Fin, bus);
			else
				return Binaria_R(V, Ini, Med-1, bus);
		}
	}
	else
	   return -1;
}	
	
int BusqBinaria(TLista L, long Bus){
	
	return Binaria_R(L.V, 1, L.tam, Bus);
}
void ModificaUno(TLista* L, int P){
	Modificar(&L->V[P]);
}
void MuestraUno(TLista* L, int P){
	MostrarCliente(L->V[P]);
}
