#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamano 30

typedef char Word [tamano];

typedef struct{
	int code;
	Word Nombre, Capital, Continent;
}RPais;

typedef RPais VecPais [tamano];
/*Ejercicio 1: Crear un programa que permita el ingreso de una lista de N países, de cada País se guarda*/
/*	la siguiente información: “Código del País, Nombre del país, Capital del país y Continente al que*/
/*	pertenece.”*/
/*	Se debe realizar la carga de la lista de países y posteriormente ordenar la lista por Código del país, luego*/
/*	utilizando un menú poder realizar las siguientes operaciones:*/
/*	a) Añadir un nuevo País preservando el orden.*/
/*	b) Dado un Código de un país, modificar la Capital que se tiene registrada.*/
/*	c) Dado un Código de un país, eliminar dicho registro.*/
/*	d) Dada una Capital, mostrar el País al que pertenece. */
RPais CargarPais();
void MostrarPais(RPais);
void ModificarPais(RPais*);

short MENU();

void CargarLista(VecPais, int*);
void OrdenarLista(VecPais, int);

void EliminarElemento(VecPais, int*);
void IngresarElemento(VecPais, int*);
void ModificarElemento(VecPais, int);
void MostrarCapital(VecPais, int);

int main() {
	
	int N;
	short opt;
	VecPais P;
	
	CargarLista(P, &N);
	OrdenarLista(P, N);
	do{
		opt=MENU();
		
		switch(opt){
		case 1: IngresarElemento(P, &N);
		break;
		
		case 2: ModificarElemento(P, N);
		break;
		
		case 3: EliminarElemento(P, &N);
		break;
			
		case 4: MostrarCapital(P, N);
		break;
			
		case 5: system("cls"); break;
		
		case 0: printf("\nSALIENDO DEL PROGRAMA"); break;
		default: printf("\nINVALIDA");	
		}
	} while(opt!=0);
	
	return 0;
}

short MENU(){
	
	short op;
	
	printf("\n===============================================");
	printf("\nElija lo que desee realizar");
	printf("\n[1] Añadir un nuevo país");	
	printf("\n[2] Modificar una capital");
	printf("\n[3] Eliminar un pais");
	printf("\n[4] Mostrar un país segun su capital");
	printf("\n[5] Si desea borrar la pantalla");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &op);
	printf("\n===============================================\n");
	
	return op;
}
	


void LeeCad(Word A, int TAM){
	int j; char c;
	fflush(stdin);
	j=0;
	c=getchar();
	
	while(j<TAM && c!=EOF && c!='\n'){
		A[j]=c;
		j++;
		c=getchar();
	}
	A[j]='\0';
	
	while(c!=EOF && c!='\n')
		c=getchar();
}

RPais CargarPais(int codigo){
	RPais Nvo;
	int N;
	N=tamano;
	
	printf("-----------------------");
	printf("\nINGRESE EL PAIS:");
	printf("\nCODIGO DE PAIS; %d", codigo);
	printf("\nPAIS: "); LeeCad(Nvo.Nombre, N);
	printf("CAPITAL: "); LeeCad(Nvo.Capital, N);
	printf("CONTINENTE: "); LeeCad(Nvo.Continent, N);

	Nvo.code=codigo;
	
	return Nvo;

}
void MostrarPais(RPais A){
	
	printf("CODIGO DE PAIS: %d",A.code);
	printf("- PAIS: %s - CAPITAL: %s", A.Nombre, A.Capital);
	printf("- CONTINENTE: %s", A.Continent);
}

int Binaria(VecPais A, int N, int Code){
	int Ini, Fin, Med;
	int Pos;
	
	Ini=1; Fin=N; Med=(Ini+Fin)/2;
	
	while(Ini<=Fin && A[Med].code!=Code){
		
		if(A[Med].code>Code)
			Fin=Med-1;
		else
			Ini=Med+1;
		Med=(Ini+Fin)/2;
		
	}
	
	if(Ini>Fin)
		Pos=Ini;
	else
		Pos=Med*(-1);
	
	return Pos;
	
}
	
	
void modificarPais(RPais* A){
	int N;
	N=tamano;
	
	printf("\nDATOS ACTUALES");
	MostrarPais(*A);
	printf("Ingreses la nueva capital: ");
	LeeCad(A->Capital, N);
}
	
	
	
void ModificarElemento(VecPais A, int N){
	int Code;
	int Pos;
	
	printf("Ingrese el código del país al que desea modificar: ");
	scanf("%d", &Code);
	
	Pos=Binaria(A, N, Code);
	
	if(Pos<0){
		Pos=Pos*(-1);
		modificarPais(&A[Pos]);
	}	
}

void MoverCargar (VecPais A, int N, int pos, int codigo){
	int i;
	
	for(i=N; i>=pos; i--){
		A[i+1]=A[i];
	}
	A[pos]=CargarPais(codigo);
}	
	
	
void CargarLista(VecPais A, int* N){
	int i, codigo, pos;
	i=1;
	
	printf("Ingrese la cantidad de elementos de la lista: "); scanf("%d", N);
	
	while(i<= *N){
		if(i!=1){
			printf("\n Ingrese el codigo: "); scanf("%d", &codigo);
			pos=Binaria(A, *N, codigo);
			if(pos>0){
				MoverCargar(A, i, pos, codigo);
				i++;
			}
			else
			   printf("El pais ya estaba");
		}
		
		else{
		   printf("\n Ingrese el codigo: "); scanf("%d", &codigo);
			A[1]=CargarPais(codigo);
			i++;
		}
	}
}
void OrdenarLista(VecPais A, int N){
	int i, j;
	RPais Aux;
	
	for(i=1; i<N; i++){
		for(j=i+1; j<=N; j++){
			if(A[i].code>A[j].code){
			
				Aux=A[i];
				A[i]=A[j];
				A[j]=Aux;
			}
		}
	}
}
	
	
void MoverBorrar(VecPais A, int N, int pos){
	int i;
	
	for(i=pos ; i<N; i++){
		A[i]=A[i+1];
	}
}
	
	
void EliminarElemento(VecPais A, int*i){
	int codigo;
	int pos;
	
	
	printf("\n Ingrese el codigo: "); scanf("%d", &codigo);
	pos=Binaria(A, *i, codigo);
	if(pos<0){
		pos= pos*(-1);
		MoverBorrar(A, *i, pos);
		*i= *i-1;
	}
	else
	   printf("El pais no está");
}



void IngresarElemento(VecPais A, int* i){
	int codigo;
	int pos;
	
	
	printf("\n Ingrese el codigo: "); scanf("%d", &codigo);
	pos=Binaria(A, *i, codigo);
	if(pos>0){
		MoverCargar(A, *i, pos, codigo);
		*i= *i+1;
	}
	else
	   printf("El pais ya estaba");
}
	
	
void MostrarCapital(VecPais A, int N){
	int i, b=0;
	Word Capital;
	
	printf("Ingrese la capital a buscar: "); LeeCad(Capital, tamano);
	
	for(i=1; i<=N; i++){
		if(strcmp(Capital, A[i].Capital)==0){
			b=1;
			MostrarPais(A[i]);
		}
	}
	if(b==0) printf("No está");
}
