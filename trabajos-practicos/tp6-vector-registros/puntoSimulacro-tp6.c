#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamano 30

typedef char Word [tamano];

typedef struct{
	Word Nombre, Domicilio, Telefono; 
	long DNI;
}Legajo;

typedef struct{
	int Numero;
	Legajo Cliente;
	int aridos;
	long FechaSol, FechaEnt;
	int Metros2;
	short status;
}RPedido;

typedef RPedido ListaENV[tamano];

RPedido IngresarPedido();
void MostrarRegistro(RPedido);

Legajo IngresarCliente();
void MostrarCliente(Legajo);

short MENU();
void CargarNuevo(ListaENV, int*);
void OrdenMostrar(ListaENV, int);
void MostrarPedidos(ListaENV, int);
void Modificar(ListaENV, int);
void MostrarFecha(ListaENV, int);
void ModificarMetros(RPedido* );
void DepurarXFecha(ListaENV, int*);

int main() {
	ListaENV List;
	int N;
	short opt;
	N=0;
	
	do{
		opt=MENU();
		switch(opt){
		case 1: CargarNuevo(List, &N); break;
		case 2: OrdenMostrar(List, N); break;
		case 3: MostrarPedidos(List, N); break;
		case 4: MostrarFecha(List, N); break;
		case 5: Modificar(List, N); break;
		case 6: DepurarXFecha (List, &N); break;
		case 7: system("cls"); break;
		case 0: printf("\n Saliendo..."); break;
		default: printf("\n INVALIDO");
		}
		
	} while(opt!=0);

	return 0;
}

void LeeCad(Word Frase, int MaxTM){
	int j; char c;
	fflush(stdin);
	c=getchar();
	j=0;
	
	while(j<MaxTM && c!= EOF && c!= '\n'){
		Frase[j]=c;
		c=getchar();
		j++;
	}
	Frase[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}


RPedido IngresarPedido(){
	RPedido Nvo;
	printf("\n Ingrese nuevo pedido");
	printf("\nCampo, Numero de pedido: "); scanf("%d", &Nvo.Numero);
	printf("\nCampo, cliente: "); 
	Nvo.Cliente=IngresarCliente();
	printf("Campo, arido (1. Arena/ 2. Ripio/ 3. Grava/ 4. Piedra): "); scanf("%d", &Nvo.aridos);
	printf("Campo, Metros: "); scanf("%d", &Nvo.Metros2);
	printf("\nCampo, Fecha de solicitud: "); scanf("%ld", &Nvo.FechaSol);
	printf("\nCampo, Fecha de entrega: "); scanf("%ld", &Nvo.FechaEnt);
	printf("\n Estatus: Solicitado");
	
	Nvo.status=0;
	return Nvo;
}
	
void AridoCartel (int A){
	
	switch(A){
	case 1: printf("Arena"); break;
	case 2: printf("Ripio"); break;
	case 3: printf("Grava"); break;
	case 4: printf("Piedra"); break;
	}
	
}
	
	
void MostrarRegistro(RPedido A){
	printf("\n---------------------------\n");
	printf("Client:");
	
	printf("\nCampo, Numero de pedido: %d", A.Numero);
	printf("\nCampo, cliente: "); 
	MostrarCliente(A.Cliente);
	printf("\nCampo, arido: "); AridoCartel(A.aridos);
	printf("Campo, Metros: %d", A.Metros2);
	printf("\nCampo, Fecha de solicitud: %ld", A.FechaSol);
	printf("\nCampo, Fecha de entrega: %ld", A.FechaEnt);
	if(A.status==0)
		printf("\n Estatus: Solicitado");
	else
		printf("\n Estatus: Entregado");
}

Legajo IngresarCliente(){
	Legajo Nvo;
	
	printf("\nNombre: "); LeeCad(Nvo.Nombre, tamano);
	printf("DNI: "); scanf("%ld", &Nvo.DNI);
	printf("Domicilio: "); LeeCad(Nvo.Domicilio, tamano);
	printf("Telefono: "); LeeCad(Nvo.Telefono, tamano);
	
	return Nvo;
}
void MostrarCliente(Legajo A){
	
	printf("\nNombre: %s  -- DNI: %ld", A.Nombre, A.DNI);
	printf("\nDomicilio %s --  Telefono %s", A.Domicilio, A.Telefono);
	
}

short MENU(){
	
	short op;
	
	printf("\n===============================================");
	printf("\nBienvenido! Elija lo que quiere realizar");
	printf("\n[1] Agregar un nuevo pedido");	
	printf("\n[2] Ordenar y mostrar");
	printf("\n[3] Mostrar pedidos según un DNI");
	printf("\n[4] Mostrar pedidos según una Fecha");
	printf("\n[5] Modificar");
	printf("\n[6] Depurar dado una fecha");
	printf("\n[7] Si desea borrar la pantalla");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("\n===============================================\n");
	
	return op;
}
int BuscarPedido(ListaENV A, int N, int Bus){
	int i;
	
	i=1;
	while(i<=N && A[i].Numero!=Bus)
		i++;
	if(i>N)
		return -1;
	else
		return i;
}
	
void Modificar(ListaENV A, int N){
	int Pos, numPedido, opt;
	
	printf("\n Ingresar Nro de pedido: "); scanf("%d", &numPedido);
	
	Pos=BuscarPedido(A, N, numPedido);
	if(Pos>0){
		
		do{printf("\n Ingrese 1 para modificar los Mts Cuadrados o 2 para modificar el Status: "); scanf("%d", &opt);
		}while(opt!=1 && opt!=2);
		
		
		if(opt==2){
			A[Pos].status=1;
			printf("\n Status cambiado");
		}
		else
		ModificarMetros(&A[Pos]);
	}	
	else
	   printf("\n No se encontró");
}


void CargarNuevo(ListaENV A, int* N){
	
	(*N)++;
	A[*N]=IngresarPedido();
	
}
	
void orden(ListaENV A, int N){
	int i; int j;
	RPedido Aux;
	
	
	for(i=1; i<N; i++){
		for(j=i+1; j<=N; j++){
			if(A[i].Cliente.DNI>A[j].Cliente.DNI){
				Aux=A[i];
				A[i]=A[j];
				A[j]=Aux;
			}
		}
	}
}
	
void mostrar(ListaENV A, int N){
	int i;
	
	for(i=1; i<=N; i++)
		MostrarRegistro(A[i]);
}
	
	
void OrdenMostrar(ListaENV A, int N){
	
	orden(A, N);
	
	mostrar(A, N);
	
	
}
void MostrarPedidos(ListaENV A, int N){
	int i;
	long DNI;
	
	printf("\nIngrese el DNI a buscar: "); scanf("%ld", &DNI);
	
	for(i=1; i<=N; i++){
		if(DNI== A[i].Cliente.DNI)
			MostrarRegistro(A[i]);
	}
	
	
}
void MostrarFecha(ListaENV A, int N){
	int i;
	long Fecha;
	
	printf("\nIngrese la fecha para mostrar: "); scanf("%ld", &Fecha);
	
	for(i=1; i<=N; i++){
		if(A[i].FechaSol==Fecha || A[i].FechaEnt==Fecha)
			MostrarRegistro(A[i]);
	}
}

void ModificarMetros(RPedido* A){
	
	printf("\n Actual: "); MostrarRegistro(*A);
	printf("\nIngrese la nueva cantidad: "); scanf("%d", &A->Metros2);
	
}
	
void CorreYBorra(ListaENV A, int* N, int pos){
	int E;
	
	for(E = pos; E < *N; E++) {
		A[E] = A[E+1];
	}
	
	(*N)--;  
}
	
void DepurarXFecha(ListaENV A, int* N){
	int i;
	long Fecha;
	i=1;
	printf("\nIngrese la fecha para depurar: "); scanf("%ld", &Fecha);
	
	while(i<= *N){
		if(Fecha > A[i].FechaEnt){
			CorreYBorra(A, N, i);
		}
		else
		   i++;
	}
}
