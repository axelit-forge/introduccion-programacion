#include <stdio.h>
#include <string.h>
#define tamano 30

typedef char Word [tamano];
typedef Word VectorCad [tamano];
typedef int VectorInt[tamano];

void cargaVectores (VectorCad, VectorCad, VectorCad, VectorInt, int*);
void Mostrar (VectorCad, VectorCad, VectorCad, VectorInt, int);

int main() {
	VectorCad Nombre, Apellido, Domicilio;
	VectorInt Edad;
	int N;
	
	cargaVectores(Nombre, Apellido, Domicilio, Edad, &N);
	Mostrar (Nombre, Apellido, Domicilio, Edad, N);
	
	return 0;
}

void LeeCad (Word A, int tam){
	int j=0; char c;
	c=getchar();
	
	while(c!=EOF && c!= '\n' && j<tam){
		A[j]=c;
		j++;
		c=getchar();
	}
	A[j]= '\0';
	while(c!=EOF && c!='\n')
		c= getchar();
}

int compareNomApe(Word Nombre, Word Apellido, Word NombreBusq, Word ApellidoBusq){
	int Rta;
	Rta = strcmp(Apellido, ApellidoBusq);
	if (Rta == 0)
		Rta= strcmp(Nombre, NombreBusq);
	
	return Rta;
}
	
	
int Binaria(VectorCad Nombre, VectorCad Apellido , int N, Word NBusq, Word ApBusq){
	int Ini, Fin, Med;
	Ini=1; Fin=N; Med= (Ini+Fin)/2;
		
	while(Ini<=Fin && compareNomApe(Nombre[Med],Apellido[Med],NBusq, ApBusq) != 0)
	{
		if(compareNomApe(Nombre[Med],Apellido[Med],NBusq, ApBusq)>0)
			Fin=Med-1;
		else
			Ini=Med+1;
		Med= (Ini+Fin)/2;
	}
	if(Ini>Fin) return Ini;
	else
		return Med;
}		

	
void ingresar (Word NombreAux, Word ApellidoAux, VectorCad Nombre, VectorCad Apellido, VectorCad Domicilio, VectorInt Edad, int pos, int N){
	int i;
	
	for (i = N; i >= pos; i--) {
		strcpy(Nombre[i + 1], Nombre[i]);
		strcpy(Apellido[i + 1], Apellido[i]);
		strcpy(Domicilio[i + 1], Domicilio[i]);
		Edad[i + 1] = Edad[i];
	}
	
	
	fflush(stdin);
	printf("Ingrse el Domicilio: ");
	LeeCad(Domicilio[pos], 30);
	strcpy(Nombre[pos], NombreAux);
	strcpy(Apellido[pos], ApellidoAux);
	printf("Ingrese la edad: "); scanf("%d", &Edad[pos]);
}
	
	
	
void cargaVectores (VectorCad Nombre, VectorCad Apellido, VectorCad Domicilio, VectorInt Edad, int* N){
	int i=1;
	int pos;
	Word NombreAux, ApellidoAux;
	
	printf("Ingrese la cantidad de Clientes: "); scanf("%d", N);
	fflush(stdin);
	
	printf("Ingrese el nombre: ");
	LeeCad(NombreAux, 30);
	printf("Ingrese el apellido: ");
	LeeCad(ApellidoAux, 30);
	printf("Ingrse el Domicilio: ");
	LeeCad(Domicilio[1], 30);
	strcpy(Nombre[1], NombreAux);
	strcpy(Apellido[1], ApellidoAux);
	printf("Ingrese la edad: "); scanf("%d", &Edad[1]);
	i++;
	
	while(i<=*N){
		fflush(stdin);
		printf("Ingrese el nombre: ");
		LeeCad(NombreAux, 30);
		printf("Ingrese el apellido: ");
		LeeCad(ApellidoAux, 30);
		
		pos= Binaria(Nombre, Apellido, i, NombreAux, ApellidoAux);
		
		if (pos == i || compareNomApe(Nombre[pos], Apellido[pos], NombreAux, ApellidoAux) != 0) {
			ingresar(NombreAux, ApellidoAux, Nombre, Apellido, Domicilio, Edad, pos, i);
			i++;
		} 
		else 
			printf("\nCliente ya presente\n");
	}
	
}

	
void Mostrar (VectorCad Nombre, VectorCad Apellido, VectorCad Domicilio, VectorInt Edad, int N) {
	int i;
	for (i = 1; i <= N; i++) {
		printf("\nCliente %d: %s %s, Domicilio: %s, Edad: %d", i, Nombre[i], Apellido[i], Domicilio[i], Edad[i]);
	}
}
