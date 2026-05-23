#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNum (int, int);
void ingresoFec (int*, int*, int*);
short verif(int, int, int);
int diames (int, int);
short verifPost (int, int, int, int, int, int);
int DaysYear (int, int, int);
int DaysTot (int, int, int, int, int, int);

int main() {
	
	int anoB, mesB, diasB;
	int anoX, mesX, diasX, cuota;
	int diasTrans=0;
	short b=-1;
	
	do{
		if(b==0) printf("\nFECHA INVALIDA VUELVA A INTENTAR");
		ingresoFec(&anoB, &mesB, &diasB);
		b=verif(anoB, mesB, diasB);
	}while (b==0||b==-1);
	
	printf("\n========================");
	printf("\nFecha a usar: %d/%d/%d", anoB,mesB,diasB);
	printf("\n========================");
	printf("\n");
	system("pause");
	
	srand(time(NULL));
	b=0;
	do{
		anoX=randomNum(anoB, 2100);
		mesX=randomNum(1, 12);
		diasX=randomNum(1, diames(mesX, anoX));
		b=verifPost(anoB, anoX, mesB, mesX, diasB, diasX);
	} while(b==0);
	
	printf("\n==========================");
	printf("\nFecha a generada: %d/%d/%d", anoX,mesX,diasX);
	printf("\n==========================");
	printf("\n");
	system("pause");
	
	
	printf("\nIngrese la cuota diaria de recargo: ");
	scanf("%d", &cuota);
	diasTrans=DaysTot(anoB, anoX, mesB, mesX, diasB, diasX);
	
	printf("\nEl total a pagar en la nueva fecha es $%d", diasTrans*cuota);
	
	
	return 0;
}

int randomNum (int R1, int R2){
	
	return rand() % (R2-R1+1) + R1;
}

void ingresoFec (int* ano, int* mes, int* dias){
	
	printf("\nIngrese la fecha a trabajar: \n");
	printf("año: ");
	scanf("%d", ano);
	printf("mes: ");
	scanf("%d", mes);	
	printf("dia: ");
	scanf("%d", dias);	
}

int diames (int m, int ano){
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
	
short verif(int ano, int mes, int dia){
	short b=0;
	
	if (ano>1900&&ano<2100)
		if(mes>0 && mes<13)
			if(dia>0 && dia<=diames(mes, ano))
				b=1;
	
	return b;
}
short verifPost (int anoA, int anoB, int mesA, int mesB, int diaA, int diaB){
	short b=1;
	if(anoA==anoB){
		if(mesA>mesB)
		b=0;
		else
			if(mesA==mesB)
				if(diaA>=diaB)
					b=0;
	}
	return b;
}

int DaysYear (int ano, int mes, int dias){
	int DiasY=0, i;
	
	for (i=1;i<mes;i++)
		DiasY+=diames(mes, ano);
	
	DiasY+=dias;
	return DiasY;
}
	
int DaysTot (int anoA, int anoB, int mesA, int mesB, int diaA, int diaB){
	int DiasT=0, i;
	
	for (i=anoA;i<anoB;i++){
		if (i%4==0)
			DiasT+=366;
		else
			DiasT+=365;
	}
	DiasT= DiasT- DaysYear(anoA, mesA, diaA);
	
	DiasT= DiasT+ DaysYear(anoB, mesB, diaB);
	
	return DiasT;
}
