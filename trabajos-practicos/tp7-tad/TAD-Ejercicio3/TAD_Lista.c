#include "TAD_Lista.h"
#include <stdio.h>

TLista CargarLista(){
	TLista Nvo;
	int i;
	printf("\n Ingrese el tamanio de la lista: "); scanf("%d", & Nvo.N);
	
	for(i=1; i<=Nvo.N; i++){
		Nvo.Alumnos[i]=CargarAlum();
	}
	return Nvo;
}
void MostrarLista(TLista L){
	int i;
	
	for(i=1; i<=L.N; i++){
		MostrarAlum(L.Alumnos[i]);
	}
}
void AgregarAlum(TLista* L){

	printf("\nIngrese el nuevo alumno: ");
	L->N++;
	L->Alumnos[L->N]= CargarAlum();
}
void ModEstado(TLista* L){
	int i;
	RFecha Comp;
	printf("\n Ingrese la fecha a la que comparar: ");
	Comp=ScanFecha();
	while (EsFecha(Comp) == 0) {
		printf("\nFecha inválida. Ingrese la Fecha de inicio nuevamente: ");
		Comp = ScanFecha();
	}
	
	for(i=1; i<= L->N; i++){
		ModificarEstado( &L->Alumnos[i], Comp);
	}
}
	
int Busqueda(TLista* L, long Bus, Word TBus){
	int i = 1;  
	int b = 0;  
	Word Aux;
		
	while (i <= L->N && b == 0) {  
		if (GetDNI(L->Alumnos[i]) == Bus) {
			GetPostGrado(L->Alumnos[i], Aux);
			if (CmpCadena(Aux, TBus) == 0) {  
				b = 1;  
			}
		}	
		i++;  
	}
	return i;
}
	

void ModxDNI_Grado(TLista* L){
	int pos;
	Word GradoBus;
	long DNIBus;
	
	printf("\n Ingrese el PostGrado a buscar para buscar: "); ScanCad(GradoBus);
	printf("\n Ingrese el DNI para buscar: "); scanf("%ld", &DNIBus);
	
	pos=Busqueda(L, DNIBus, GradoBus);
	
	if(pos>0){
		ModificarAlum(&L->Alumnos[pos]);
		L->N--;
		printf("\n Alumno encontrado");
	}
	else
	   printf("\n Alumno no encontrado");
}
	
void Ordenar (TLista* L){
	int i, j;
	RAlumno Aux;
	for(i=1; i< L->N; i++){
		for(j=i+1; j<= L->N; j++){
			if(CmpNombres(L->Alumnos[i], L->Alumnos[j])>0){
				
				Aux=L->Alumnos[i];
				L->Alumnos[i]=L->Alumnos[j];
				L->Alumnos[j]= Aux;
			}
		}
	}
}
	
	
TLista CrearXPostGrado(TLista L, Word T){
	TLista NuevaLista;
	int i=1;
	NuevaLista.N=0;
	
	while(i<= L.N){
		if(CmpAlumno(L.Alumnos[i],T)==0){
			NuevaLista.N++;
			NuevaLista.Alumnos[NuevaLista.N]=L.Alumnos[i];
		}
		i++;	
	}
	
	Ordenar(&NuevaLista);
	
	return NuevaLista;
}

	
	
	
