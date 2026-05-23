#include "TAD_Cadena.h"

#include <ctype.h>


void limpiar_buffer() {
	char c=getchar();
	while ( c!=EOF && c!='\n') c++;
}


void strlwr(TCad T) {
	int i=0;
	while(T[i]!='\0') {
		T[i]=tolower(T[i]);
	}

}

void LeeCad(TCad T, int TM){			/*privado*/
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
	strlwr(T);
	if(T[0]>97 && T[0]<123)
		T[0]-=32;
}
void PrintCad(TCad T){
	printf("%s", T);
}
	
int CmpCad(TCad A, TCad B){
	return strcmp(A, B);
}
void CpyCad(TCad A, TCad B){
	strcpy(A, B);
}
