#ifndef BITWISE_UTILS_H
#define BITWISE_UTILS_H

#include <stdint.h>
#include <stdbool.h>

// Representa un conjunto de hasta 64 banderas o estados independientes
typedef uint64_t bitmaskT;

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna la máscara con el bit en 'bit_pos' encendido (1), sin alterar los demás.
 */
bitmaskT bitmaskSet(bitmaskT mask, uint8_t bit_pos);

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna la máscara con el bit en 'bit_pos' apagado (0), sin alterar los demás.
 */
bitmaskT bitmaskClear(bitmaskT mask, uint8_t bit_pos);

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna true si el bit en 'bit_pos' está encendido (1), false si está en (0).
 */
bool bitmaskCheck(bitmaskT mask, uint8_t bit_pos);

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna la máscara con el bit en 'bit_pos' invertido (si era 0 pasa a 1, si era 1 pasa a 0).
 */
bitmaskT bitmaskToggle(bitmaskT mask, uint8_t bit_pos);


// Definición de las posiciones de los bits para cada permiso
#define PERMISOS_READ    0  // Bit 0
#define PERMISOS_WRITE   1  // Bit 1
#define PERMISOS_EXECUTE 2  // Bit 2
#define PERMISOS_DELETE  3  // Bit 3

/**
 * PRE: -
 * POST: Recibe 4 booleanos y devuelve un único byte (uint8_t) con los bits
 * correspondientes encendidos según cada bandera sea true.
 * Los bits del 4 al 7 deben quedar en 0.
 */
uint8_t crearPermisos(bool r, bool w, bool x, bool d);

/**
 * PRE: 'permisos_A' y 'permisos_B' deben ser bytes de permisos válidos (solo bits 0-3 activos).
 * POST: Devuelve un nuevo byte que contiene ÚNICAMENTE los permisos que ambos
 * usuarios tienen en común (intersección de conjuntos).
 */
uint8_t interseccionPermisos(uint8_t permisos_A, uint8_t permisos_B);

/**
 * PRE: -
 * POST: Retorna true si la cantidad de bits encendidos (1) en la máscara es PAR.
 * Retorna false si la cantidad de bits encendidos es IMPAR.
 * Una máscara con cero bits encendidos se considera PAR (retorna true).
 */
bool paridadBitmask(bitmaskT mask);

/**
 * PRE: -
 * POST: Devuelve un nuevo conjunto que contiene los estados de ambos conjuntos (A UNION B).
 */
bitmaskT conjuntoUnion(bitmaskT conjunto_A, bitmaskT conjunto_B);

/**
 * PRE: -
 * POST: Devuelve un nuevo conjunto que contiene SOLO los estados que están en ambos conjuntos a la vez (A INTERSECCION B).
 */
bitmaskT conjuntoInterseccion(bitmaskT conjunto_A, bitmaskT conjunto_B);

/**
 * PRE: -
 * POST: Devuelve un nuevo conjunto con los estados que están en A pero NO están en B (A - B).
 */
bitmaskT conjuntoDiferencia(bitmaskT conjunto_A, bitmaskT conjunto_B);

#endif

#ifdef BITWISE_UTILS_IMPLEMENTATION
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

#endif
