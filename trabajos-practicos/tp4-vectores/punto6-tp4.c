#include <stdio.h>
#include <ctype.h>

#define tamano 50
/*Ejercicio 6: Dada una lista A de M caracteres alfanuméricos en minúsculas, se solicita ingresarla y*/
/*	continuación, utilizando un menú de opciones, permitir:*/
/*	a) Insertar un nuevo carácter en A, en la posición P, la cual es ingresada por teclado.*/
/*	b) Eliminar el elemento anterior al primer carácter de tipo vocal de la lista*/
/*	c) Cambiar los caracteres que representan a las vocales (a, e, i, o, u), presentes en el arreglo A por*/
/*	su equivalente en mayúsculas (A, E, I, O, U).*/
/*	d) Mostrar el vector A. */
typedef char phrase [tamano];

void ingresoListaIncondicionada (phrase,int*);
short menu();
void ReplaceChar(phrase, int);
void EliminarCond(phrase, int*);
void MinusToMayus (phrase, int);
void MostrarVector(phrase, int);

int main() {
	phrase List;
	int M;
	short Option;
	
	ingresoListaIncondicionada(List, &M);
	
	do{
		Option= menu();
		switch(Option)
		{
		case 1: ReplaceChar(List, M);	
		break;	
		
		case 2: EliminarCond(List, &M);	
		break;	
		
		case 3: MinusToMayus(List, M);
		break;
		
		case 4: MostrarVector(List, M);
		break;
		
		case 0: printf("\n--->SALIR PROGRAMA");
		break;
		
		default: printf("\nOPCION NO VALIDA\n");
		}
	} while(Option!=0);
	
	return 0;
}

void ingresoListaIncondicionada (phrase F, int*Cantidad){
	int i;
	
	printf("Ingrese la cantidad de caracteres de la lista: ");
	scanf("%d%*c", Cantidad);
	
	for(i=1 ;i <= *Cantidad ; i++){
		printf("F[%d] = ", i);
		scanf("%c%*c", &F[i]);
	}	
}

short menu(){
	short opt;
	
	printf("\n===============================================");
	printf("\n[1] Insertar un nuevo carácter en A, en la posición P");	
	printf("\n[2] Eliminar el elemento anterior al primer carácter de tipo vocal de la lista");
	printf("\n[3] Hacer mayusculas las vocales");
	printf("\n[4] Mostrar la lista");
	printf("\n[0] Salir del programa \n Elegido: ");
	scanf("%hd", &opt);
	printf("===============================================\n");
	
	return opt;
}

void ReplaceChar(phrase List, int M){
	int posicion;
	char X;
	
	printf("\nIngreses la posicion del caracter a reemplazar: ");
	scanf("%d%*c", &posicion);
	
	printf("\nIngrese el elemento: ");
	scanf("%c", &X);
	printf("El elemento %c, reemplaza a %c, en la posicion %d", X, List[posicion], posicion);
	List[posicion]=X;
}

short lector(char C){
	
	short b;
	
	if(isdigit(C))
		b=1;
	else
	{
		switch(C){
		case 'a': case 'e': case 'i': case 'o': case 'u': b=-1; break;
		default: if (isalpha(C)) b=0;
		}
	}
	return b;
}	

void EliminarCond(phrase List, int*M){
	int i=1, j;
	short B=0;
	char aux;
	
	while (i<=*M && B==0){
		aux=tolower(List[i]);
		if(lector(aux) == -1){
			for(j=i-1; j<= *M; j++){
				List[j]= List[j+1];
			}
			(*M)--;
			B=1;
		}
		i++;
	}
	if (i>*M)
		printf("No hay vocales");
}


void MinusToMayus (phrase List, int M){
	int i;
	for(i=1; i<=M; i++){
		if(lector(List[i])==-1)
			List[i]=toupper(List[i]);
	}
}

void MostrarVector(phrase List, int M){
	int i;
	printf("\n F{ ");
	
	for(i=1; i<=M; i++){
		printf("%c, ", List[i]);
	}
	printf("}");
}
