#include <stdio.h>
#include <assert.h>
#include <inttypes.h> // Para PRIu64
#include "bitwise_utils.h"

// Función auxiliar para ver los últimos 8 bits en la consola
void print_bits_8(bitmask_t mask) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (mask & (1ULL << i)) ? 1 : 0);
    }
    printf("\n");
}

int main(void) {
    bitmask_t mascara = 0b1010;

    printf("--- Estado Inicial ---\n");
    printf("Valor decimal: %" PRIu64 "\n", mascara);
    printf("Bits:          "); print_bits_8(mascara);
    printf("\n");

    bitmask_t resultado_set = bitmask_set(mascara, 2);
    printf("Probando SET en bit 2:\n");
    printf("Bits esperados: 00001110 -> Obtenido: "); print_bits_8(resultado_set);


    bitmask_t resultado_clear = bitmask_clear(mascara, 1);
    printf("Probando CLEAR en bit 1:\n");
    printf("Bits esperados: 00001000 -> Obtenido: "); print_bits_8(resultado_clear);


    printf("Probando CHECK:\n");
    printf("¿Bit 1 está encendido? (Esperado: SI) -> %s\n", bitmask_check(mascara, 1) ? "SI" : "NO");
    printf("¿Bit 2 está encendido? (Esperado: NO) -> %s\n", bitmask_check(mascara, 2) ? "SI" : "NO");
    printf("\n");

    bitmask_t resultado_toggle = bitmask_toggle(mascara, 2);
    resultado_toggle = bitmask_toggle(mascara, 0);
    printf("Probando TOGGLE en bit 1:\n");
    printf("Bits esperados: 00001011 -> Obtenido: "); print_bits_8(resultado_toggle);

    return 0;
}