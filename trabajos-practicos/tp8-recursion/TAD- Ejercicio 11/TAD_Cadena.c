#include "TAD_Cadena.h"
#include <string.h>
#include <stdio.h>

void Vaciado(){				/*privado*/
	char c;
	c=getchar();
	if(c!=EOF && c!='\n')
		Vaciado();
}

void LeeCad_R(TCad T, int tam, int j){				/*privado*/
	char c;
	c=getchar();
	if(j<tam && c!=EOF && c!='\n'){
		T[j]=c;
		LeeCad_R(T, tam, j+1);
	}
	else{
		T[j]='\0';
		if(j>=tam) Vaciado();
	}
}

void PrintCad(TCad T){
	printf("%s", T);
}
void ScanCad(TCad T){
	fflush(stdin);
	LeeCad_R(T, MAXC-1, 0);
}
int CmpCad(TCad A, TCad B){
	return strcmp(A, B);
}
void CpyCad(TCad A, TCad B){
	strcpy(A, B);
}
