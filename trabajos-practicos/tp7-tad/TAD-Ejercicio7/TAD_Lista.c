#include "TAD_Lista.h"
#include <stdio.h>

void CargaVector(TLista* A){ 	/*privado*/
	int i;
	for(i=1; i<= A->N; i++){
		A->Empleados[i]= CargarEmpleado();
	}
}
	
void OrdenBurb(TLista*A){
	int i, j;
	REmpleado Aux;
	
	for(i=1; i<A->N; i++){
		for(j=A->N; j>=i; j--){
			if(CmpRegXReg(A->Empleados[j], A->Empleados[j-1])<0){
				Aux = A->Empleados[j];
				A->Empleados[j] = A->Empleados[j - 1];
				A->Empleados[j - 1] = Aux;
			}
		}
	}
}	

TLista CargarLista(){
	TLista Nvo;
	
	printf("\n Ingrese el tamanio de la lista: "); scanf("%d", & Nvo.N);
	CargaVector(&Nvo);
	OrdenBurb(&Nvo);
	
	return Nvo;
}
	
int BusquedaBin(TLista*L, long Bus){
	int pos;
	int Ini, Fin, Med;
	Ini=1; Fin=L->N; Med=(Ini+Fin)/2;
	
	while(Ini<=Fin && (CmpRegXDNI(L->Empleados[Med], Bus) !=0)){
		
		if((CmpRegXDNI(L->Empleados[Med], Bus))>0)
			Fin=Med-1;
		else
			Ini=Med+1;
		Med=(Ini+Fin)/2;
	}
	if(Ini>Fin)
		pos=Ini;
	else
		pos=Med*(-1);
	return pos;
}
void CorreYAgrega(TLista* L, int pos, REmpleado Aux){
	int i;
	
	for(i=L->N; i>= pos; i++){
		L->Empleados[i+1]=L->Empleados[i];
	}
	(L->N)++;
	L->Empleados[pos]= Aux;
	
}
	
void AgregarEmpleado(TLista* L){
	REmpleado Aux;
	long DNIBUS;
	int pos;
	
	printf("\nIngrese el nuevo empleado"); 
	Aux=CargarEmpleado();
	DNIBUS=ReturnDNI(Aux);
	
	pos=BusquedaBin(L, DNIBUS);
	
	if(pos>0){
		CorreYAgrega(L, pos, Aux);
		printf("\nElemento agregado");
	}
	else 
	   printf("\n El elemento ya estaba presente");
}
	
void CorreYBorra(TLista* L, int pos){
	int i;	
	for(i=pos; i< L->N; i++){
		L->Empleados[i]= L->Empleados[i+1];
	}
	L->N--;
}
	
void EliminarEmpleado(TLista* L){
	long DNIB;
	int pos;
	printf("\n Ingrese el DNI del empleado a eliminar: "); scanf("%ld", &DNIB);
	
	pos=BusquedaBin(L, DNIB);
	
	if(pos<0){
		pos= pos*(-1);
		CorreYBorra(L, pos);
		printf("\n Empleado elminado");
	}
	else
	   printf("\n Ese documento no le pertenece a ningun empleado");
	
}
	
void mostrarMayor(int A, int B, int C){
	if(A>B && A>C)
		printf("\nEl turno con mas empleados es la ma�ana con %d empleados", A);
	else{
		if(B>A && B>C)
			printf("\n El turno con m�s empleados es la tarde con %d Empleados", B);
		else
			printf("\n El turno con m�s empleados es la noche con %d Empleados", C);
	}
}	
	
	
void MaxEmpleados(TLista L){
	int CM=0, CT=0, CN=0;
	int turn, i;
	
	for(i=1; i<= L.N ; i++){
		turn=ReturnTurn(L.Empleados[i]);
		switch(turn){
		case 1: CM++; break;
		case 2: CT++; break;
		case 3: CN++; break;
		}
	}
	mostrarMayor(CM, CT, CN);
}
void MostrarXTurno(TLista L){
	int T;
	int i;
	
	printf("\n Ingrese el turno a mostrar (1 Ma�ana/ 2.Tarde/ 3.Noche): "); scanf("%d", &T);
	
	for(i=1; i<= L.N; i++){
		if(CmpTurno(L.Empleados[i], T))
			MostrarEmpleado(L.Empleados[i]);
	}
}
