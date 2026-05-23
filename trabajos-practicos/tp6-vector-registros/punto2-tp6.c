#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamano 30

typedef char Word [tamano];

typedef struct{
	long code;
	Word Apellido, Nombre;
	Word Domicilio;
	long Saldo;
}RCliente;

typedef RCliente ListaReg[tamano];

/*Ejercicio 2: Un banco mantiene la información de sus clientes en un array de registros (Lista de clientes).*/
/*	De cada Cliente se almacena la siguiente información: “Número de cuenta, Apellido y Nombre del cliente,*/
/*	Domicilio del cliente, Saldo de la cuenta. “*/
/*	Se solicita escribir un programa que permita realizar la carga de las cuentas de N Clientes de un banco y*/
/*	luego mediante un menú realizar las siguientes operaciones:*/
/*	a) Permitir actualizar el domicilio de un cliente, dado su número de cuenta*/
/*	b) Realizar un depósito (es decir, dado un monto a depositar y una cuenta, actualizar el saldo).*/
/*	c) Realizar un retiro (es decir, dado un monto a retirar y una cuenta, actualizar el saldo si es que el saldo es mayor o igual al importe a retirar).*/
/*	d) Realizar una transferencia entre cuentas (es decir, dado un monto a transferir, una cuenta origen y*/
/*												 una cuenta destino, actualizar el saldo destino si es que el saldo origen es mayor o igual al importe a*/
/*												 transferir).*/
/*	Ejercicio 3: Realice los cambios apropiados en el Ejercicio 2, para impedir la carga de un número de*/
/*	cuenta ya existente en la lista y que la lista de clientes se ordene por el número de cuenta a medida que*/
/*	se ingresan los clientes. */

RCliente IngresarCliente (long );
void MostrarCliente( RCliente);

void CargarLista(ListaReg, int*);
short MENU();

void ActualizarDomicilio(ListaReg, int);
void Deposito(ListaReg, int);
void Retiro(ListaReg, int);
void Transferencia(ListaReg, int);
void MenuAdmin(ListaReg, int);

int main() {
	ListaReg List;
	int N;
	short opt;
	
	CargarLista(List, &N);
	
	do{
		opt=MENU();
		
		switch(opt){
		case 1: ActualizarDomicilio(List, N); break;
		case 2:	Deposito(List, N); break;
		case 3: Retiro (List, N); break;
		case 4: Transferencia(List, N); break;	
		case 5: MenuAdmin(List, N); break;	
		case 0: printf("\nSaliendo..."); break;
		default: printf("\nINVALIDO");	
		}
		
	} while(opt!=0);
	
	return 0;
}

void LeeCad(Word A, int MaxTM){
	int j; char c;
	fflush(stdin);
	j=0;
	c=getchar();
	
	while(j<MaxTM && c!=EOF && c!='\n'){
		A[j]=c;
		c=getchar();
		j++;
	}
	A[j]='\0';
	
	while(c!=EOF && c!='\n')
		c=getchar();
}
short MENU(){
	
	short op;
	
	printf("\n===============================================");
	printf("\nElija lo que desee realizar");
	printf("\n[1] Actualizar un domicilio");	
	printf("\n[2] Realizar un depósito");
	printf("\n[3] Realizar una retiro");
	printf("\n[4] Realizar una transferencia");
	printf("\n[5] Entrar al menu de Administrador");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("\n===============================================\n");
	
	return op;
}
	
void MostrarLista(ListaReg A, int N){
	int i;
	
	for(i=1; i<=N; i++){
		MostrarCliente(A[i]);
	}
	
}
void MostrarListaCondicional( ListaReg A, int N, int opt){
	int i;
	long cond;
	
	if(opt==2){
		printf("\n Ingrese el valor para la condicion: "); scanf("%ld", &cond);
		for(i=1; i<=N; i++){
			if(A[i].Saldo>cond)
				MostrarCliente(A[i]);
		}
	}
	else{
	   for(i=1; i<=N; i++){
			if(A[i].Saldo<0)
				MostrarCliente(A[i]);
	   }
	}
}
	
	
void controller(ListaReg List, int N){
	int opt;
	printf("\n Elegido: ");
	scanf("%d", &opt);
	printf("\n===============================================\n");
	
	switch(opt){
	case 1: MostrarLista(List, N); break;
	case 2: MostrarListaCondicional(List, N, 1); break;
	case 3: MostrarListaCondicional(List, N, 2); break;
	default: printf("Saliendo..."); break;
	}
}
	
	
void MenuAdmin(ListaReg A, int N){
	
	printf("\n===============================================");
	printf("\nElija lo que desee realizar ");
	printf("\n.-1 Mostrar Lista completa de clientes");	
	printf("\n.-2 Mostrar Clientes con saldo =0 o negativo");
	printf("\n.-3 Mostrar Clientes con saldo mayor al ingresado");
	
	controller(A, N);
}
	
RCliente IngresarCliente (long code){
	RCliente Nvo;
	
	printf("-------------------------");
	printf("\nCARGAR CLIENTE");
	printf("\nCódigo: %ld", code);
	printf("\nApellido: "); LeeCad(Nvo.Apellido, tamano);
	printf("Nombre: "); LeeCad(Nvo.Nombre, tamano);
	printf("Domicilio: "); LeeCad(Nvo.Domicilio, tamano);
	printf("Saldo: "); scanf("%ld", &Nvo.Saldo);
	
	Nvo.code=code;
	
	return Nvo;
}
void MostrarCliente( RCliente A){
	printf("\nCliente---");
	printf("\nCódigo: %ld", A.code);
	printf("\nApellido: %s - Nombre: %s ", A.Apellido, A.Nombre);
	printf("\nDomicilio: "); puts(A.Domicilio);
	printf("\nSaldo: $%ld", A.Saldo);
}

int Binaria(ListaReg A, int N, long code){
	int Ini, Fin, Med;
	int pos;
	
	Ini=1; Fin=N; Med= (Ini+Fin)/2;
	
	while(Ini<=Fin && A[Med].code!=code){
		
		if(A[Med].code>code)
			Fin= Med-1;
		else
			Ini= Med+1;
		Med=(Ini+Fin)/2;
	}
	if(Ini>Fin)
		pos= Ini;
	else
		pos= Med*(-1);
	
	return pos;
}

void MoverCargar(ListaReg A, int N, int pos, long code){
	int i;
	
	for(i=N; i>=pos; i--){
		A[i+1]=A[i];
	}
	A[pos]=IngresarCliente(code);
}


	
void CargarLista(ListaReg A, int* N){
	int i, code, pos;
	i=1;
	printf("Ingrese la cantidad de clientes: "); scanf("%d", N);
	
	while(i<= *N){
		if(i!=1){
			printf("\nIngrese el código del cliente: "); scanf("%d", &code);
			pos=Binaria(A, i, code);
			
			if(pos>0){
				MoverCargar(A, i, pos, code);
				i++;
			}
			else printf("\nEl cliente ya estaba presente");

		}
		else{
			printf("\nIngrese el código del cliente: "); scanf("%d", &code);
			A[i]=IngresarCliente(code);
			i++;
		}
	}
}
	
void ModificarCliente(RCliente* A){
	printf("\n El cliente a editar: ");
	MostrarCliente(*A);
	
	printf("\nIngrese el nuevo domicilio: "); LeeCad(A->Domicilio, tamano);
}
	
	
void ActualizarDomicilio(ListaReg A, int N){
	int code, pos;
	printf("\nIngrese el código para buscar al cliente: "); scanf("%d", &code);
	
	pos=Binaria(A, N, code);
	
	if(pos<0){
		pos=pos*(-1);
		ModificarCliente(&A[pos]);
	}
	printf("\n Actualizado: ");
	puts(A[pos].Domicilio);
}
	
void Deposito(ListaReg A, int N){
	int code, pos; 
	long monto;
	
	printf("\n Ingrese el cliente al cual depositar(codigo): "); scanf("%d", &code);
	printf("\n Ingrese monto a pagar: "); scanf("%ld", &monto);
	pos= Binaria(A, N, code);
	
	if(pos<0){
		pos=pos*(-1);
		A[pos].Saldo+= monto;
		printf("\n Nuevo saldo del cliente es: $%ld ", A[pos].Saldo);
	}
	else
	   printf("No se encontró al cliente");
}
void Retiro(ListaReg A, int N){
	int code, pos; 
	long monto;
	
	printf("\n Ingrese el cliente al cual retirar(codigo): "); scanf("%d", &code);
	printf("\n Ingrese monto a retirar: "); scanf("%ld", &monto);
	pos= Binaria(A, N, code);
	
	if(pos<0){
		pos=pos*(-1);
		if(A[pos].Saldo>monto){
			A[pos].Saldo-= monto;
			printf("\n Nuevo saldo del cliente es: $%ld ", A[pos].Saldo);
			
		}
		else
		   printf("\n El cliente no tenia fondos suficientes");
	}
	else
	   printf("No se encontró al cliente");
}
void Transferencia(ListaReg A, int N){
	int code, pos1, pos2; 
	long monto;
	
	printf("\n Ingrese el cliente origen (codigo): "); scanf("%d", &code);
	pos1= Binaria(A, N, code);
	
	printf("\n Ingrese el cliente destino(codigo): "); scanf("%d", &code);
	pos2= Binaria(A, N, code);
	
	
	printf("\n Ingrese monto a pagar: "); scanf("%ld", &monto);
	if(pos1<0 && pos2<0){
		pos1= pos1*(-1); pos2=pos2*(-1);
		if(A[pos1].Saldo>monto){
			A[pos1].Saldo-=monto;
			A[pos2].Saldo+=monto;
		}
		else 
		   printf("Saldo insuficiente");
	}
	else
	   printf("\n Un cliente no se encontro");
}
