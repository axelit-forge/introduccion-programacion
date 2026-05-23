#include <stdio.h>
#include <math.h>

void real6dig (float*);

int main() {
	
	float real;
	int pent, pdec, cE=0;
	int cntent, cntdec;
	
	real6dig(&real);
	printf("\nEl numero es %f", real);
	
	pent= floor(real);
	pdec= (int)((real - pent) * 1000000 + 0.5);
	
	while (pdec%10==0&&cE<6){
		pdec/=10;
		cE++;
	}
	printf("\nLa parte real es = %d - y la parte decimal es= %d", pent, pdec);
	
	if (pent!=0){
		cntent=(log10(pent)) + 1;
		printf("\n\n La cantidad de cifras de la parte entera es de %d", cntent);
	}
	if (pdec != 0){
		cntdec=(log10(pdec)) + 1;
		printf("\n La cantidad de cifras de la parte entera es de %d",cntdec);
	}
	
	return 0;
}


void real6dig (float *num){
	printf("Ingrese el numero real (6 digitos de precision) = ");
	scanf("%f.6", num);
}
