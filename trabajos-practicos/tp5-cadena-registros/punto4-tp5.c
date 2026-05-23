#include <stdio.h>
#include <string.h>
#define tamano 30

typedef char Word [tamano];

void LeeCad (Word, int);
void IngresoFrase(Word);
void longPalabra(Word);
void CantPalabras(Word);

int main() {
	Word Frase;
	
	IngresoFrase(Frase);
	longPalabra(Frase);
	CantPalabras(Frase);
	
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

void IngresoFrase(Word A){
	int N=tamano;
	printf("Ingrse la frase, de máximo %d caracteres:  ", N);
	LeeCad(A, N);
}
	
	
void longPalabra(Word A){
	int i=0, j=0;
	Word Aux, larga={"a"};
	
	while (A[i] != '\0') {  
		j = 0;
		
		while (A[i] != ' ' && A[i] != '\0') {
			Aux[j] = A[i];
			j++;
			i++;
		}
		Aux[j] = '\0';  
		
		if (strlen(larga) < strlen(Aux)) {
			strcpy(larga, Aux);  
		}
		
		if (A[i] == ' ') {
			i++; 
		}
	}
	
	printf("\nLa palabra más larga es %s, con un largo de %d", larga, strlen(larga));
}
void CantPalabras(Word A){
	int i=0, cont=0;
	int B=0;
	
	while (A[i] != '\0') {  
		if (A[i] != ' ')
			B=1;
		if (A[i] == ' ')
			if(B==1){
				B=0;
				cont++;
			}
		i++;
	}
	if(B==1) cont++;
	
	printf("\n La cantidad de palabras es %d", cont);
}
