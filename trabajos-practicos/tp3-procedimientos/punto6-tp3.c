#include <stdio.h>
#include <math.h>

void SepararPartes (float, int*, int*);
int modificar (int);


int main() {
	
	float Real=0;
	int ParteEnt, ParteDec;
	
	printf("Ingrese el número real: ");
	scanf("%f.04", &Real);
	
	SepararPartes(Real,&ParteEnt,&ParteDec);
	
	ParteEnt=modificar(ParteEnt);
	ParteDec=modificar(ParteDec);
	
	printf("\n--->Valores modificados %d.%d", ParteEnt, ParteDec);
	
	return 0;
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

int modificar (int X){
	
	short d;
	int acu, xcopia;
	int potencia10 = 1;
	
	acu=0;
	xcopia=X;
	
	while (xcopia>0)
	{
		d=xcopia%10;
		
		if(d%2!=0)
			d=d-1;
		
		acu = acu + (d * potencia10);
		
		potencia10 *= 10;
		
		xcopia/=10;
	}
	
	return acu;
}
