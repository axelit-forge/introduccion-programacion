#include "TAD_Cadena.h"
#include <stdio.h>


void limpiar_buffer() {
	char c=getchar();
	while ( c!=EOF && c!='\n') c++;
}

void LeeCad(TCad T, int TM){
	int j; char c;
	limpiar_buffer();
	c=getchar();
	j=0;
	while(j<TM && c!=EOF && c!='\n'){
		T[j]=c;
		c=getchar();
		j++;
	}
	T[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}



void ScanCad(TCad T){
	LeeCad(T, TamC);
}
void PrintCad(TCad T){
	printf("%s", T);
}
