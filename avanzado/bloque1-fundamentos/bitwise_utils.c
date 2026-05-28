#include "bitwise_utils.h"

bitmaskT bitmaskSet(bitmaskT mask, uint8_t bit_pos) {
    return mask | (1ULL << bit_pos);
}

bitmaskT bitmaskClear(bitmaskT mask, uint8_t bit_pos) {
    return mask & ~(1ULL << bit_pos);
}

bool bitmaskCheck(bitmaskT mask, uint8_t bit_pos) {
    bool bit = (mask >> bit_pos) & 1;
    return bit;
}

bitmaskT bitmaskToggle(bitmaskT mask, uint8_t bit_pos) {
    return mask ^ (1ULL << bit_pos);
}

uint8_t crearPermisos(bool r, bool w, bool x, bool d) {
    uint8_t permisos = (r << PERM_READ) | (w << PERM_WRITE) | (x << PERM_EXECUTE) | (d << PERM_DELETE );
    return permisos;
}

uint8_t interseccionPermisos(uint8_t permisos_A, uint8_t permisos_B) {
    return (permisos_A & permisos_B);
}

bool paridadBitmask(bitmaskT mask) {
    int count = 0;
    while (mask != 0) {
        mask = mask & (mask - 1);
        count ++;
    }
    return ~ count & 1;
}

bitmaskT conjuntoUnion(bitmaskT conjunto_A, bitmaskT conjunto_B) {
    return conjunto_A | conjunto_B;
}

bitmaskT conjuntoInterseccion(bitmaskT conjunto_A, bitmaskT conjunto_B) {
    return conjunto_A & conjunto_B;
}

bitmaskT conjuntoDiferencia(bitmaskT conjunto_A, bitmaskT conjunto_B) {
    return conjunto_A & ~conjunto_B;
}