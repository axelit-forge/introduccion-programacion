#ifndef TAD_COMPLEX_H
#define TAD_COMPLEX_H

typedef struct{
	float Real, Imag;
}RComplex;

RComplex InComplex();
void ShowComplex(RComplex);
RComplex SumComplex(RComplex, RComplex);
RComplex RestComplex(RComplex, RComplex);
RComplex ProdComplex(RComplex, RComplex);
RComplex CocComplex(RComplex, RComplex);


#endif
