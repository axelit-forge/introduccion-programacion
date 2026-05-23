#include "TAD_Lista.h"
#include <stdio.h>

tLista EmpezarLista();
void Menu(tLista*, tLista*);

int main(void){
	
	tLista Head;
	tLista Artista;
	
	Artista=EmpezarLista();
	Head=EmpezarLista();
	
	Menu(&Head, &Artista);
	
	FreeLista(&Head);				/*Pq la teoria dice q e buenaa practica asi q pq no*/
	FreeLista(&Artista);
	
	return 0;
}

tLista EmpezarLista(){
	int n;
	tLista Pri;
	Pri = Inicializar();
	
	printf("\n Ingrese la cantidad de canciones a cargar: ");
	scanf("%d", &n);
	Pri=CargarLista(n);
	
	return Pri;
}

void opciones(){
	printf("-------------------------------");
	printf("\n \t -MENU DE OPCIONES- \n");
	printf("\n  1) Agregar una nueva canción a la lista (manteniendo el orden),");
	printf("\n 	2) Mostrar la lista de canciones,");
	printf("\n 	3) Mostrar los datos de las canciones de un interprete dado,");
	printf("\n 	4) Mostrar los datos de las canciones de un álbum dado, ");
	printf("\n 	5) Obtener la frecuencia de cada género en porcentaje. ");
	printf("\n");
}

void Menu (tLista* Pri, tLista* ListaB){
	int op;
	
	do{
		opciones();
		scanf("%d", &op);
		switch(op){
		case 1: AgregarUno(Pri); break;
		case 2: MostrarLista(*Pri); break;
		case 3: MostrarCondicionado(*Pri, 2); break;
		case 4: MostrarCondicionado(*Pri, 3); break;
		case 5: MostrarFrec(*Pri); break;
		case 0: printf("\n Saliendo...");
		default: printf("\n Opcion invalida");
		}
	} while(op!=0);
}
	
	
