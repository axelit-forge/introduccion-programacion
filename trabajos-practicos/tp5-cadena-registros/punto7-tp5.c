#include <stdio.h>
#include <string.h>
#define tamano 30

typedef char Word[tamano];

typedef struct{
	Word Ciudad, Barrio, Calle, Numero, Departamento;
}Domicilio;

typedef struct{
	int Year, Month, Day;
}Fecha;

typedef struct{
	Word Nombre, Apellido;
	long DNI; 
	Fecha Nac;
	Domicilio Casa;
}Alumno;

Alumno IngresarAlumno();
void MostrarRegistro(Alumno);

int main() {
	Alumno Al1, Al2, aux;
	
	Al1=IngresarAlumno();
	
	Al2=IngresarAlumno();
	
	if(strcmp(Al1.Apellido,Al2.Apellido)>0){
		aux=Al1;
		Al1=Al2;
		Al2=aux;
		}
	
	MostrarRegistro(Al1);
	MostrarRegistro(Al2);
	
	
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

Domicilio IngresarDomicilio(){
	Domicilio Nvo;
	fflush(stdin);
	printf("Ciudad: ");
	LeeCad(Nvo.Ciudad, 30);
	printf("Barrio: ");
	LeeCad(Nvo.Barrio, 30);
	printf("Calle: ");
	LeeCad(Nvo.Calle, 30);
	printf("Numero: ");
	LeeCad(Nvo.Numero, 30);
	printf("Departamento: ");
	LeeCad(Nvo.Departamento, 30);

	return Nvo;
}

Fecha IngresarFecha(){
	Fecha Nvo;
	printf("Año: "); scanf("%d", &Nvo.Year);
	printf("Mes: "); scanf("%d", &Nvo.Month);
	printf("Dia: "); scanf("%d", &Nvo.Day);
	
	return Nvo;
}

Alumno IngresarAlumno(){
	Alumno Nvo;
	
	printf("INGRESE UN NUEVO ALUMNO");
	
	printf("\nCampo- Nombre: ");
	LeeCad(Nvo.Nombre, 30);
	printf("\nCampo- Apellido: ");
	LeeCad(Nvo.Apellido, 30);
	printf("\nCampo- DNI: "); 
	scanf("%ld", &Nvo.DNI);
	printf("\nCampo- Fecha de Nacimiento: ");
	Nvo.Nac=IngresarFecha();
	printf("\nCampo- Domicilio: ");
	Nvo.Casa=IngresarDomicilio();
	
	return Nvo;
}
void MostrarDomicilio(Domicilio Casa){
		
		printf("Ciudad: %s, Barrio %s, Calle %s, Numero %s, Departamento: %s", Casa.Ciudad, Casa.Barrio, Casa.Calle, Casa.Numero, Casa.Departamento);
	
}
		
void MostrarFecha(Fecha Nac){

	printf("%02d/%02d/%d", Nac.Day, Nac.Month, Nac.Year);
}
	
	
	
void MostrarRegistro(Alumno Nvo){
	
	printf("\nALUMNO");
	
	printf("\nCampo- Nombre: ");
	puts(Nvo.Nombre);
	printf("\nCampo- Apellido: ");
	puts(Nvo.Apellido);
	printf("\nCampo- DNI: %ld", Nvo.DNI);
	printf("\nCampo- Fecha de Nacimiento: ");
	MostrarFecha(Nvo.Nac);
	printf("\nCampo- Domicilio: ");
	MostrarDomicilio(Nvo.Casa);
	
}
	
	
	
