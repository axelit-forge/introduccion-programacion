#include <stdio.h>
#include <assert.h>
#include <inttypes.h> // Para PRIu64
#include "bitwise_utils.h"

// Función auxiliar para ver los últimos 8 bits en la consola
void print_bits_8(bitmaskT mask) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (mask & (1ULL << i)) ? 1 : 0);
    }
    printf("\n");
}

int main(void) {


    /*Las operaciones bitwise permiten hacer operaciones complejas de union, interseccion y diferencias a una velocidad
     *extravagante, mediante operaciones sencillas se es capaz de ver si un numero es par sin necesidad de revisar su mod
     *con un simple num&1, se puede contener utilizar todos los bits de una mask como un estado distinto al que
     *se representa, permitiendo operaciones muy complejas simplificarlas a pocos pasos y son veloces.*/
  printf("Funciona todo");
  return 0;
}