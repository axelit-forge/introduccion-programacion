#include "TAD_Empleado.h"
#include "TAD_Cadena.h"
#include <stdio.h>





	
REmpleado CargarEmpleado(){
	REmpleado Nvo;
	
	printf("\n-------------------------------------");
	printf("\nCarga de nuevo empleado\n");
	printf("\nDNI: "); scanf("%ld", & Nvo.DNI);
	printf("\nApellido: "); ScanCad(Nvo.Apellido);
	printf("\nNombre: "); ScanCad(Nvo.Nombre);
	printf("\nFecha de alta (aaammdd): "); scanf("%ld", & Nvo.FecAlta);
	printf("\nTelefono: "); ScanCad(Nvo.Telefono);
	printf("\nTurno (1.Manana/2.Tarde/3.Noche) :"); scanf("%d", & Nvo.Turno);
	return Nvo;
}
void MostrarEmpleado (REmpleado A){
	
	printf("\n-------------------------------------");
	printf("\nEmpleado\n");
	printf("\nDNI: %ld", A.DNI);
	printf("\nApellido: "); PrintCad(A.Apellido);
	printf("\nNombre: "); PrintCad(A.Nombre);
	printf("\nFecha de alta (aaammdd): %ld", A.FecAlta);
	printf("\nTelefono: "); PrintCad(A.Telefono);
	switch(A.Turno){
	case 1: printf("\n Turno: Manana"); break;
	case 2: printf("\n Turno: Tarde"); break;
	case 3: printf("\n Turno: Noche"); break;
	}
}

int CmpRegXDNI (REmpleado A, long DNI){
	if(A.DNI> DNI)
		return 1;
	else{
		if(A.DNI == DNI)
			return 0;
		else
			return -1;
	}
}

int CmpRegXReg (REmpleado A, REmpleado B){
	if(A.DNI>B.DNI)
		return 1;
	else{
		if(A.DNI==B.DNI)
			return 0;
		else
			return -1;
	}
}

int CmpTurno (REmpleado A, int Turno){
	return(A.Turno==Turno);
}
	
long ReturnDNI (REmpleado A){
	return A.DNI;
}
int ReturnTurn (REmpleado A){
	return A.Turno;
}
	
