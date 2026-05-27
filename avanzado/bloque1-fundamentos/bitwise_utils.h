#ifndef BITWISE_UTILS_H
#define BITWISE_UTILS_H

#include <stdint.h>
#include <stdbool.h>

// Representa un conjunto de hasta 64 banderas o estados independientes
typedef uint64_t bitmask_t;

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna la máscara con el bit en 'bit_pos' encendido (1), sin alterar los demás.
 */
bitmask_t bitmask_set(bitmask_t mask, uint8_t bit_pos);

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna la máscara con el bit en 'bit_pos' apagado (0), sin alterar los demás.
 */
bitmask_t bitmask_clear(bitmask_t mask, uint8_t bit_pos);

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna true si el bit en 'bit_pos' está encendido (1), false si está en (0).
 */
bool bitmask_check(bitmask_t mask, uint8_t bit_pos);

/**
 * PRE: 'bit_pos' debe ser un valor entre 0 y 63.
 * POST: Retorna la máscara con el bit en 'bit_pos' invertido (si era 0 pasa a 1, si era 1 pasa a 0).
 */
bitmask_t bitmask_toggle(bitmask_t mask, uint8_t bit_pos);

#endif