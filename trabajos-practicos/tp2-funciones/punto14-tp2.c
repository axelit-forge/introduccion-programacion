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
	
	int N, i, diasTrans; 
	int anoB, mesB, diasB;
	int anoX, mesX, diasX;
	short b;
	int acu=0, cont=0;
	
	printf("Ingrese la cantidad de fechas: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		
		b=-1;
		
		ingresoFec(&anoB, &mesB, &diasB);
		b=verif(anoB, mesB, diasB);
		
		if (b==1){
		printf("\n========================");
		printf("\nFecha a usar: %d/%d/%d", anoB,mesB,diasB);
		printf("\n");
		
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
		printf("\n");
		
		diasTrans=DaysTot(anoB, anoX, mesB, mesX, diasB, diasX);
		printf("\n\n>Los dias entre la fecha ingresada y la generada son %d\n", diasTrans);
		
		if (diasTrans%2==0)
		{	
			acu+=diasTrans;
			cont++;
		}	
		}
		else
			printf("Fecha invalida");
		
	}
	
	if(cont>0)
		printf("\t\nEl promedio de los dias pasados entre fechas que eran pares es de %d", acu/cont);
	else
		printf("\t\n-->Ninguno cumplió la condicion");
	
	
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

