#include <stdio.h>
#define MAXV 30

typedef struct{
	int Hora;
	int Minut;
}Tiempo;


typedef struct{
	int Patente;
	short Tipo;
	Tiempo Egreso, Ingreso;
	int Importe;
}RVeh;

typedef RVeh Estacionamiento[MAXV];

/*Ejercicio 8:*/
/*	Crear una estructura de datos de array de registros para almacenar los datos de los vehículos del*/
/*	estacionamiento. Los datos a almacenar son: “Nro. de Patente, Tipo de Vehículo (auto, camioneta, moto),*/
/*	Hora y Minutos de Ingreso, Hora y Minutos de Egreso, Importe Pagado”*/
/*	Crear 2 listas de vehículos:*/
/*	? La primer lista llamada INGRESOS, es para almacenar los vehículos que ingresan, en esta lista la*/
/*	hora y minutos de egreso y el importe pagado no se debe cargar.*/
/*	? La segunda lista llamada EGRESOS, es para almacenar los datos de los vehículos que se retiraron,*/
/*	en donde se modificará la hora y minutos de egreso y el importe pagado.*/
/*	Se pide realizar un programa que permita cargar la primer lista INGRESOS de N vehículos y luego a*/
/*	través de un menú permita las siguientes operaciones:*/
/*	a) Agregar un nuevo vehículo a la lista INGRESOS.*/
/*	b) Retirar un vehículo (Para esta acción se solicita el Nro. de Patente del vehículo, se buscará el vehículo*/
/*							en INGRESOS y se deben copiar los datos del vehículo a la lista EGRESOS, para cargar la*/
/*							información de salida. Posteriormente se debe eliminar el vehículo de la lista INGRESOS.*/
/*							c) Eliminar de la lista EGRESOS todos aquellos vehículos de un Tipo determinado por el usuario. */
Tiempo CargarHora ();
void MostrarTiempo (Tiempo);

RVeh CargarVeh();
void MostrarVeh(RVeh, int);

void CargarLista(Estacionamiento, int*);
void MostrarListas(Estacionamiento, int, Estacionamiento, int);

short MENU();
void Ingresar(Estacionamiento, int*);
void Retirar (Estacionamiento, int*, Estacionamiento, int*);
void EliminarEgresos(Estacionamiento, int*);

int main() {
	
	Estacionamiento Ingreso, Egreso;
	int N=0, M=0;
	short opt;
	
	CargarLista(Ingreso, &N);
	
	do{
		opt=MENU();
		
		switch(opt){
		case 1: 
			Ingresar(Ingreso, &N);
			break;
			
		case 2: 
			Retirar(Ingreso, &N, Egreso, &M); 
			break;
		
		case 3:
			EliminarEgresos(Egreso, &M);
			break;
		
		case 4:
			MostrarListas(Ingreso, N, Egreso, M);
		}
		
	} while(opt!= 0);
	
	
	
	
	return 0;
}

Tiempo CargarHora (){
	Tiempo Nvo;
	
	printf("\n Hora: "); scanf("%d", &Nvo.Hora);
	printf("Minutos: "); scanf("%d", &Nvo.Minut); 
	return Nvo;
}
void MostrarTiempo (Tiempo A){
	
	printf("\n Hora: %d", A.Hora);
	printf("\t -Minutos: %d", A.Minut); 
}

RVeh CargarVeh(){
	RVeh Nvo;
	
	printf("\nINGRESE NUEVO VEHICULO\n");
	printf("Patente: "); scanf("%d", &Nvo.Patente);
	printf("\n Tipo de vehículo (1.auto; 2. Camioneta; 3 Moto): "); scanf("%hd", &Nvo.Tipo);
	printf("\n Hora de ingreso: ");
	Nvo.Ingreso=CargarHora();
	
	return Nvo;
}
void MostrarVeh(RVeh A, int Opt){
	
	printf("\n--------------------------\nVehiculo\n");
	printf("\nPatente: %d", A.Patente);
	printf("\nTipo: ");
	switch(A.Tipo){
	case 1: printf("Auto"); break;
	case 2: printf("Camioneta"); break;
	case 3: printf("Moto"); break;
	}
	printf("\nHora ingreso: "); MostrarTiempo(A.Ingreso);
	
	if(Opt==1){
		printf("\n Hora de Egreso: "); MostrarTiempo(A.Egreso);
		printf("\n Importe: $%d", A.Importe);
	}
}

void CargarLista(Estacionamiento A, int* N){
	int i;
	printf("\n Ingrese La cantidad de vehiculos a cargar: "); scanf("%d", N);
	for(i=1; i<= *N; i++){
		A[i]=CargarVeh();
	}
}
void MostrarListas(Estacionamiento A, int N, Estacionamiento B, int M){
	int i, j;
	printf("\n LISTAS COMPLETAS\n");
	printf("\n Ingresos");
	for(i=1; i<=N; i++)
		MostrarVeh(A[i], 0);
	printf("\n Egresos");
	for(j=1; j<=M; j++)
		MostrarVeh(B[j], 1);
}

short MENU(){
	short op;
	
	printf("\n===============================================");
	printf("\nBienvenido! Elija lo que quiere realizar");
	printf("\n[1] Ingresar un vehículo");	
	printf("\n[2] Retirar un vehiculo");
	printf("\n[3] Eliminar de egresos");
	printf("\n[4] Mostrar las listas");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("\n===============================================\n");
	
	return op;
}
void Ingresar(Estacionamiento Ing, int* N){
	
	(*N)++;
	Ing[*N]= CargarVeh();
	
}
	
int Busqueda( Estacionamiento A, int N, int Bus){
	int i;
	i=1;
	while(i<=N && A[i].Patente!=Bus){
		i++;
	}
	if(i<=N)
		return i;
	else
		return -1;
}
	
void MoveryCompletar( RVeh Elem, Estacionamiento E, int* M){
	(*M)++;
	printf("\n Ingrese el horario de egreso: "); Elem.Egreso= CargarHora();
	printf("\n Inrese el importe $"); scanf("%d", &Elem.Importe);
	
	E[*M]= Elem;
}

void CorreyBorra(Estacionamiento E, int *M, int pos){
	int k;
	
	for(k=pos; k<*M; k++)
		E[k]=E[k+1];
	(*M)--;
}
	
	
void Retirar (Estacionamiento A, int* N, Estacionamiento E, int* M){
	int PatenteBus;
	int pos;
	
	printf("\n Ingrese la patente a buscar: "); scanf("%d", &PatenteBus);

	pos=Busqueda(A, *N, PatenteBus); 
	if(pos>0){
		MoveryCompletar(A[pos], E, M); 
		CorreyBorra(A, N, pos);
	}
	else
		printf("\n Patente no encontrada");
}


void EliminarEgresos(Estacionamiento E, int* M){
	int i;
	int type;
	
	printf("\n Ingrese el tipo del que quiere eliminar de la lista");
	printf("\n |. Automoviles / 2.Camionetas / 3.Motocicletas: "); scanf("%d", &type);
	
	i=1;
	while(i<=*M){
		if(type== E[i].Tipo)
			CorreyBorra(E, M, i);
		else
			i++;
	}
}
