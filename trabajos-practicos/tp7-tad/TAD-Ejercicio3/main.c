#include "TAD_Lista.h"
#include <stdio.h>

short Menu();

int main (void){
	short opt;
	TLista Lis, Nvo;
	Word PostG;
	Lis=CargarLista();
	
	
	
	do{
		
		scanf("%hd", &opt);
		
		switch(opt){
		case 1: AgregarAlum(&Lis); break;
		case 2: ModxDNI_Grado(&Lis); break;
		case 3: 
			printf("Ingreses el postgrado"); ScanCad(PostG);
			Nvo= CrearXPostGrado(Lis, PostG);
			MostrarLista(Nvo);
			break;
		case 4: ModEstado(&Lis); break;
		case 5: MostrarLista(Lis); break;
		case 0: printf("Salir del programa"); break;
		}
		
	} while(opt!=0);
	
	
	
}
