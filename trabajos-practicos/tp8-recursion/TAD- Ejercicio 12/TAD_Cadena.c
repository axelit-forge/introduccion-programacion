#include "TAD_Cadena.h"
#include <string.h>
#include <stdio.h>

void Vaciado(){				/*privado*/
	char c;
	c=getchar();
	if(c!=EOF && c!='\n')
		Vaciado();
}
	
void LeeCad(TCadena T, int tam, int j){				/*privado*/
	char c;
	c=getchar();
	if(j<tam && c!=EOF && c!='\n'){
		T[j]=c;
		LeeCad(T, tam, j+1);
	}
	else{
		T[j]='\0';
		if(j>=tam) Vaciado();
	}
}


void cargar_cadena(TCadena cad){
	fflush(stdin);
	LeeCad(cad,19, 0);
}

int compara_cadena(TCadena cad1, TCadena cad2){
	if (strcmp(cad1, cad2)==1) return 1; /*cad1 > cad2*/
			else if (strcmp(cad1, cad2)==0) return 0; /*cad1 = cad2*/
						else return -1; /*cad1 < cad2*/
}
