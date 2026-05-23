#ifndef TAD_FECHA_H
#define TAD_FECHA_H

typedef struct{
	int Year;
	int Month;
	int Day;
}RFecha;

RFecha ScanFecha();
void PrintFecha(RFecha);
int CheckYear(RFecha, RFecha);
short EsFecha(RFecha);
short CmpFecha(RFecha, RFecha);

#endif
