#include "TAD_Cadena.h"
#include <stdio.h>
#include <string.h>

void limpiar_buffer() {
	char c=getchar();
	while ( c!=EOF && c!='\n') c++;
}

void LeeCad(Word T, int TM){
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
	
void ScanCad(Word T){
	LeeCad(T, MAXC);
}
void PrintCad(Word T){
	printf("%s", T);
}
	
int CmpCadena(Word A, Word B){
	return strcmp(A, B);
}

void CadCpy(Word A, Word B){
	strcpy(A, B);
}
