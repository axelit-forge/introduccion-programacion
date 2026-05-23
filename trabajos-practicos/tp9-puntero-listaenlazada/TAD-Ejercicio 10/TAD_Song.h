#ifndef TAD_SONG_H
#define TAD_SONG_H

#include "TAD_Cadena.h"
#include <stdio.h>

typedef struct{
	int Code;
	TCad Nombre, Artista, Album; 
	int Genre;
}Song;

Song CargaCancion(int);
void MostrarCancion (Song);
int CmpCampoCad(Song, TCad, int);							/*Usamos 1 para nombre, 2 Interprete(Artista), 3 Album */
int CmpCodig(Song, int);
int CmpCanciones (Song, Song);
int CmpGenre(Song, int);
void MostrarGenero(int);

#endif
