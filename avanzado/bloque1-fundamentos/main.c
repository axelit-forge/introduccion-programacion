#include <stdio.h>
#include <stddef.h>
#include <assert.h>

#define ARITMETICA_UTILS_IMPLEMENTATION
#include "aritmetica_utils.h"


int main(void) {

    static uint8_t memoria_global[1024];

    void* buffer_inicio = &memoria_global[0];
    void* buffer_limite = &memoria_global[1024];
    void* offset_actual = buffer_inicio;

    printf("=== Probando Asignador Manual (Simulador de Arena) ===\n\n");

    void* bloque_1 = simularAlloc(&offset_actual, buffer_limite, 3, 1);
    printf("Bloque 1 (3 bytes, alig 1):  Inicia en %p | Próximo offset: %p\n", bloque_1, offset_actual);

    void* bloque_2 = simularAlloc(&offset_actual, buffer_limite, 8, 8);
    printf("Bloque 2 (8 bytes, alig 8):  Inicia en %p | Próximo offset: %p\n", bloque_2, offset_actual);

    unsigned long dir_bloque_2 = (unsigned long)bloque_2;
    assert(dir_bloque_2 % 8 == 0);
    printf("\n¡Asignación con alineación exitosa! El bloque 2 está en una dirección divisible por 8.\n");

    return 0;
}