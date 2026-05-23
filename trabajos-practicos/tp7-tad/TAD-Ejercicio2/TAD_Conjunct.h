#ifndef TAD_CONJUNCT_H
#define TAD_CONJUNCT_H

#define MAXC 50

typedef char Vector[MAXC];
typedef struct{
	Vector Elem;
	int N;
}TConjunto;

TConjunto GenConjunto ();
void ShowConjunto(TConjunto);
void AgregarElem(TConjunto*, char);
int Pertenece(TConjunto, char);
int ContieneA(TConjunto, TConjunto);
TConjunto Union(TConjunto, TConjunto);
TConjunto Interseccion(TConjunto, TConjunto);
TConjunto Resta(TConjunto, TConjunto);
TConjunto DifSimetrica(TConjunto, TConjunto);
int Cardinal(TConjunto);

#endif
