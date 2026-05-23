#ifndef TAD_CADENA_H
#define TAD_CADENA_H

#define MAXC 30

typedef char Word[MAXC];

void limpiar_buffer();
void ScanCad(Word);
void PrintCad(Word);
int CmpCadena(Word, Word);
void CadCpy(Word, Word);

#endif
