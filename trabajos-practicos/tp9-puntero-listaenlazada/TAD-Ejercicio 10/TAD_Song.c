#include "TAD_Song.h"


void MostrarOpcionesGenre(){
	printf("\n [1] Rock, [2] Pop, [3] Hip Hop, [4] Latino, [5] Otro");
}
void MostrarGenero(int genre){
	switch(genre){
	case 1: printf(" Rock "); break;
	case 2: printf(" Pop "); break;
	case 3: printf(" HipHop "); break;
	case 4: printf(" Latino "); break;
	case 5: printf(" Otro "); break;
	}
}
int CmpGenre(Song A, int B){
	return (A.Genre==B);
}

Song CargaCancion(int Codigo){
	Song Nvo;

	printf("\n-----------------------------");
	printf("\n Nueva cancion:\n");
	printf("\n Codigo: %d", Codigo);
	Nvo.Code=Codigo;
	printf(" Nombre: "); ScanCad(Nvo.Nombre);
	printf(" Artista: "); ScanCad(Nvo.Artista);
	printf(" Album: "); ScanCad(Nvo.Album);
	MostrarOpcionesGenre();
	printf(" Genero: "); 
	scanf("%d", &Nvo.Genre);
	
	return Nvo;
}
	
void MostrarCancion (Song S){
	
	printf("\nCodigo: %d", S.Code);
	printf("\nNombre: %s    -    Artista: %s", S.Nombre, S.Artista);
	printf("\nAlbum: %s    -    Genero: ", S.Album);
	MostrarGenero(S.Genre);
	printf("\n ");
}
int CmpCampoCad(Song S, TCad Cad, int opt){
	int resp;
	switch (opt){
	case 1: resp = CmpCad(S.Nombre, Cad); break;
	case 2: resp = CmpCad(S.Artista, Cad); break;
	case 3: resp = CmpCad(S.Album, Cad); break;
	default: printf("\n ERROR: Comparacion fuera de los limites");
	}
	return resp;
}

int CmpCodig(Song S, int Codigo){
	return (S.Code>Codigo)-(S.Code<Codigo);
}
int CmpCanciones (Song S, Song T){
	return (S.Code>T.Code)-(S.Code<T.Code);
}
