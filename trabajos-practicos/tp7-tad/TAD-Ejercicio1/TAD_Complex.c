#include "TAD_Complex.h"
#include <stdio.h>


RComplex InComplex(){
	RComplex Nvo;
	printf("\n Parte Real: "); scanf("%f", & Nvo.Real);
	printf("Parte Imaginaria: "); scanf("%f", & Nvo.Imag);
	
	return Nvo;
}
void ShowComplex(RComplex A){
	if(A.Imag>=0)
		printf("\n Numero: %.2f+%.2fi", A.Real, A.Imag);
	else
		printf("\n Numero: %.2f%.2fi", A.Real, A.Imag);
}
RComplex SumComplex(RComplex A, RComplex B){
	RComplex Rdo;
/*	? Suma: (a + b.i) + (c + d.i) = (a + c) + (b + d).i*/
	Rdo.Real= A.Real + B.Real;
	Rdo.Imag= A.Imag + B.Imag;
	
	return Rdo;
}
RComplex RestComplex(RComplex A, RComplex B){
	RComplex Rdo;
/*	Resta: (a + b.i) (c + d.i) = (a - c) + (b - d).i*/
	Rdo.Real= A.Real - B.Real;
	Rdo.Imag= A.Imag - B.Imag;
	
	return Rdo;
}
RComplex ProdComplex(RComplex A, RComplex B){
	RComplex Rdo;
/*	Producto: (a + b.i) * (c + d.i) = (ac - bd) + (ad + bc).i*/
	Rdo.Real= ((A.Real * B.Real) - (A.Imag * B.Imag));
	Rdo.Imag= ((A.Real * B.Imag) + (B.Real * A.Imag));
	
	return Rdo;
}
RComplex CocComplex(RComplex A, RComplex B){
	RComplex Rdo;
	float C;
/*	División: (a + b.i) / (c + d.i) = [ (ac + bd)/(c2 + d2) ] + [ (bc - ad)/ (c2 + d2)].i*/
	C= (B.Real * B.Real + B.Imag * B.Imag);
	Rdo.Real= ( (A.Real * B.Real + A.Imag * B.Imag) / C);
	Rdo.Imag= ( (A.Imag * B.Real - A.Real * B.Imag) / C);
	
	return Rdo;
}

