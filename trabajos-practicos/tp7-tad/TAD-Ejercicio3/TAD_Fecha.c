#include "TAD_Fecha.h"
#include <stdio.h>


RFecha ScanFecha(){
	RFecha Nvo;
	printf("\nFecha: \n");
	printf("Anio: "); scanf("%d", &Nvo.Year);
	printf("Mes: "); scanf("%d", &Nvo.Month);	
	printf("Dia: "); scanf("%d", &Nvo.Day);	
	return Nvo;
}
void PrintFecha(RFecha A){
	
	printf("\nFecha: \n");
	printf("Anio: %d", A.Year);
	printf("Mes: %02d", A.Month);	
	printf("Dia: %02d", A.Day);	
}


int diames (int m, int ano){			/*Privado, reutilizado del tp como todos los modulos de ac� xdxdxd*/
	int dias;
	
	switch(m){
	case 4: case 6: case 9: case 11: dias=30; break;
	case 2: 
		if(ano%4==0||(ano%400==0&&ano%100!=0)) dias=29;
		else 
			dias=28; 
		break;
	default: dias=31;
	}
	return dias;
}

short EsFecha(RFecha F){
	short b=0;
	
	if (F.Year>1900&&F.Year<2100)
		if(F.Month>0 && F.Month<13)
		if(F.Day>0 && F.Day<=diames(F.Month, F.Day))
		b=1;
	
	return b;
}
short CmpFecha(RFecha FA, RFecha FB){
	long Acu1, Acu2;
	
	Acu1= FA.Year+ FA.Month*100 + FA.Year*10000;
	Acu2= FB.Year+ FB.Month*100 + FB.Year*10000;
	return (Acu1>Acu2) - (Acu1<Acu2);
}

int DaysYear (int ano, int mes, int dias){								/*Privado*/
	int DiasY=0, i;
	
	for (i=1;i<mes;i++)
		DiasY+=diames(mes, ano);
	
	DiasY+=dias;
	return DiasY;
}

int DaysTot (RFecha A, RFecha B){					/*Privado: Calcula el dia total, primero iguala los a�os sumando DiasT mientras controla el a�o, luego, toma las fechas*/
	int DiasT=0, i;									/*Ej: la fecha 2006/07/12 y 2006/08/12 y calcula que desde el 1 de enero de 2005 hasta la fecha destino pasaron X dias,*/
													/*Y le resta los d�as que pasaron desde el 1 de enero de 2005 hasta la fecha inicio, haciendo q sea la cantidad exacta de dias pasados*/
	for (i=A.Year;i<B.Year;i++){
		if (i%4==0)
			DiasT+=366;
		else
			DiasT+=365;
	}
	DiasT= DiasT- DaysYear(A.Year, A.Month, A.Day);
	
	DiasT= DiasT+ DaysYear(B.Year, B.Month, B.Day);
	
	return DiasT;
}		
	
int CheckYear(RFecha Comp, RFecha A){
	return (DaysTot(Comp, A)>365);
};
	
	
