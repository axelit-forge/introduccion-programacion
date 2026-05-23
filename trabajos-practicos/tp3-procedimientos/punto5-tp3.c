#include <stdio.h>
#include <math.h>

float ingresarR(float);
void SepararPartes (float, int*, int*);

int main() {
	
	float Real=0;
	int ParteEnt, ParteDec;
	
	
	Real=ingresarR(Real);
	
	SepararPartes(Real,&ParteEnt,&ParteDec);
	
	printf("La parte entera es %d, y la parte decimal %d", ParteEnt,ParteDec);
	
	return 0;
}

float ingresarR(float X){
	printf("Ingrese el número real: ");
	scanf("%f.04", &X);
	return X;
}


void SepararPartes (float Real, int*ParteEntera, int*ParteDecimal)	{	
	
	int cE=0;
	
	*ParteEntera=floor(Real);
	*ParteDecimal= (Real-*ParteEntera)*10000;
	
	
	while (*ParteDecimal%10==0&&cE<4){
		*ParteDecimal/=10;
		cE++;
	}

}
