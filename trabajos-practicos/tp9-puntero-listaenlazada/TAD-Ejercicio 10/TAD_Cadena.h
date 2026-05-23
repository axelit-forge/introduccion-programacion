#ifndef TAD_CADENA_H
#define TAD_CADENA_H

#include <string.h>
#include <stdio.h>
#define TamC 30
typedef char TCad[TamC];

void PrintCad(TCad);
void ScanCad(TCad);
int CmpCad(TCad, TCad);
void CpyCad(TCad, TCad);


#endif
