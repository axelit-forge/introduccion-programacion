#include <stdio.h>
#include "TAD_Alumno.h"

void IngresoFechas(RAlumno * Nvo){
	
	printf("\nFecha de inicio: ");
	Nvo->Inicio = ScanFecha();
	
	while (EsFecha(Nvo->Inicio) == 0) {
		printf("\nFecha inválida. Ingrese la Fecha de inicio nuevamente: ");
		Nvo->Inicio = ScanFecha();
	}
	
	printf("\nFecha de finalización: ");
	Nvo->Fin = ScanFecha();
	
	while (EsFecha(Nvo->Fin) == 0 || CmpFecha(Nvo->Fin, Nvo->Inicio) < 0) {
		printf("\nFecha de finalización inválida o anterior a la Fecha de inicio. Intente nuevamente: ");
		Nvo->Fin = ScanFecha();
	}
}

RAlumno CargarAlum(){
	RAlumno Nvo;
	int estadoInput;
	
	printf("\n-------------------------------------");
	printf("\nCarga de nuevo alumno\n");
	printf("\nDNI: "); scanf("%ld", & Nvo.DNI);
	printf("\nApellido y Nombre: "); ScanCad(Nvo.ApeNombre);
	printf("\nTitulo: "); ScanCad(Nvo.Grado);
	printf("\nPostGrado: "); ScanCad(Nvo.PostGrado);
	IngresoFechas(&Nvo);
	printf("\nEstado (0. En curso / 1. Pendiente / 2. Finalizado / 3. Baja): ");
	scanf("%d", &estadoInput);
	
	if (estadoInput >= 0 && estadoInput <= 3) {
		Nvo.Estado = (Status)(estadoInput);
	} else {
		printf("\nEstado inválido, se asignará 'Pendiente' por defecto.\n");
		Nvo.Estado = Pendiente; 
	}
	return Nvo;
}
void MostrarAlum(RAlumno A){
	
	
	printf("\n-------------------------------------");
	printf("\nAlumno\n");
	printf("\nDNI: %ld", A.DNI);
	printf("\nApellido y Nombre: "); PrintCad(A.ApeNombre);
	printf("\nTitulo: "); PrintCad(A.Grado);
	printf("\nPostGrado: "); PrintCad(A.PostGrado);
	printf("\nFecha de inicio"); PrintFecha(A.Inicio);
	printf("\nFecha de finalizacion"); PrintFecha(A.Fin);
	switch(A.Estado){
	case 0: printf("\n Estado: En curso"); break;
	case 1: printf("\n Estado: Pendiente"); break;
	case 2: printf("\n Estado: Finalizado"); break;
	case 3: printf("\n Estado: Baja"); break;
	}
	
}
void ModificarAlum(RAlumno* Mod){
	int estadoInput;
	printf("\nModifique el alumno\n");
	printf("\nApellido y Nombre: "); ScanCad(Mod->ApeNombre);
	printf("\nFecha de inicio"); ScanFecha(Mod->Inicio);
	printf("\nFecha de finalizacion"); ScanFecha(Mod->Fin);
	printf("\nEstado (0. En curso / 1. Pendiente / 2. Finalizado / 3. Baja): ");
	scanf("%d", &estadoInput);
	
	if (estadoInput >= 0 && estadoInput <= 3) {
		Mod->Estado = (Status)(estadoInput);
	} else {
		printf("\nEstado inválido, se asignará 'Pendiente' por defecto.\n");
		Mod->Estado = Pendiente; 
	}
}
	
long GetDNI(RAlumno A){
	return A.DNI;
}
void GetPostGrado(RAlumno A, Word T){
	CadCpy(T, A.PostGrado);
}
int CmpNombres(RAlumno A, RAlumno B){
	return CmpCadena(A.ApeNombre, B.ApeNombre);
}
void ModificarEstado(RAlumno* A, RFecha F){
	if( (CheckYear(F, A->Inicio)) >0)
		A->Estado= Baja;
}
int CmpAlumno(RAlumno A, Word B){
	return CmpCadena(A.PostGrado, B);
}


