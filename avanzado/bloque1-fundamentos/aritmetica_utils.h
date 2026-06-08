#ifndef ARITMETICA_UTILS_H
#define ARITMETICA_UTILS_H

#include <stdint.h>
#include <stddef.h>

/**
 * PRE: 'puntero_base' debe ser una dirección válida.
 * POST: Retorna la dirección de memoria avanzada exactamente 'bytes_a_mover' bytes.
 * Ojo: la aritmética de punteros estándar depende del tipo; esta función
 * debe moverse estrictamente byte por byte (dirección pura).
 */
void* avanzarBytes(void* punteroBase, size_t bytesMover);

/**
 * PRE: -
 * POST: Retorna la dirección 'direccion_actual' redondeada hacia arriba al
 * siguiente múltiplo de 'alineacion'. 
 * Ej: alinear_puntero(11, 8) -> Retorna 16
 * Ej: alinear_puntero(8, 8)  -> Retorna 8 (ya estaba alineado)
 * Restricción: Debe resolverse usando operaciones bitwise para máxima velocidad.
 */
void* alinearPuntero(void* direccionActual, size_t alineacion);
/**
 * PRE: 'p_offset' debe apuntar a un puntero válido dentro del buffer.
 * 'buffer_inicio' y 'buffer_limite' definen las fronteras de la memoria total.
 * POST: Busca la posición actual apuntada por '*p_offset', la ALINEA según el
 * requisito, verifica si el bloque 'size' entra antes de 'buffer_limite',
 * avanza el '*p_offset' al final del bloque asignado y devuelve el
 * puntero ALINEADO al inicio del nuevo bloque.
 * Si no hay espacio suficiente, devuelve NULL.
 */
void* simularAlloc(void** p_offset, void* buffer_limite, size_t size, size_t alineacion);

#endif

//  IMPLEMENTACIÓN (Estilo STB) ---
#ifdef ARITMETICA_UTILS_IMPLEMENTATION

void* avanzarBytes(void* punteroBase, size_t bytesMover) {
    char * temporal = punteroBase;
    temporal =  temporal + bytesMover;
    return (void*) temporal;
}

void* alinearPuntero(void* direccionActual, size_t alineacion) {
    unsigned long direccion =(unsigned long) direccionActual;
    return (void*) ((direccion + (alineacion-1)) & ~(alineacion-1));
}

void* simularAlloc(void** p_offset, void* buffer_limite, size_t size, size_t alineacion) {
    void * punteroAlineado = alinearPuntero(*p_offset, alineacion);
    void * punteroFinal = avanzarBytes(punteroAlineado, size);
    if (punteroFinal > buffer_limite)
        return NULL;

    *p_offset = punteroFinal;
    return punteroAlineado;
}

#endif