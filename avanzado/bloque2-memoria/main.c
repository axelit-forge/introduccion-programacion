#include <stdio.h>
#include <assert.h>
#include <stdint.h>

// Activamos
#define ARENA_IMPLEMENTATION
#include "arena.h"

typedef struct {
    uint8_t  id;
    uint64_t timestamp;
    uint32_t flags;
} EventoPrueba;

int main(void) {
    printf("=== INICIANDO TEST: ARENA ALLOCATOR ===\n\n");

    // TEST 1: Creación e Inicialización
    size_t capacidadInicial = 1024; // 1 KB
    Arena arena = arenaCreate(capacidadInicial);

    assert(arena.buffer != NULL && "El buffer de la arena no debe ser NULL");
    assert(arena.capacidad == capacidadInicial);
    assert(arena.offset == 0);
    assert(arenaGetFreeSpace(&arena) == capacidadInicial);
    printf("  [PASS] Test 1: Creacion de la Arena impecable.\n");

    // TEST 2: Asignación Alineada y Libres
    // Pedimos 3 bytes (rompe alineación)
    uint8_t* p1 = (uint8_t*) arenaAlloc(&arena, 3);
    assert(p1 != NULL);

    // Pedimos un struct que requiere alineación de 8 bytes
    EventoPrueba* evento = (EventoPrueba*) arenaAllocAligned(&arena, sizeof(EventoPrueba), 8);
    assert(evento != NULL);

    // Verificación de Hardware: la dirección debe ser divisible por 8
    assert(((uintptr_t)evento % 8) == 0 && "La direccion devuelta debe estar alineada a 8 bytes");
    printf("  [PASS] Test 2: Alineacion de hardware correcta (%p).\n", (void*)evento);

    // TEST 3: arenaAllocZero (Memoria Limpia)
    EventoPrueba* eventoLimpio = (EventoPrueba*) arenaAllocZero(&arena, sizeof(EventoPrueba));
    assert(eventoLimpio->id == 0);
    assert(eventoLimpio->timestamp == 0);
    assert(eventoLimpio->flags == 0);
    printf("  [PASS] Test 3: AllocZero garantiza memoria limpia en 0.\n");

    // TEST 4: arenaSave / arenaRestore (Simulación de Ámbito / AST)
    ArenaMarker fotoAmbito = arenaSave(&arena);
    size_t offsetAntesDelAmbito = arena.offset;

    // Asignamos basura temporal dentro del ámbito "fantasma"
    void* basura1 = arenaAlloc(&arena, 128);
    void* basura2 = arenaAlloc(&arena, 64);
    (void)basura1; (void)basura2; // Evitamos warnings de variables no usadas

    assert(arena.offset > offsetAntesDelAmbito); // El offset avanzó

    // Salimos del ámbito: Restauramos la foto
    arenaRestore(&arena, fotoAmbito);
    assert(arena.offset == offsetAntesDelAmbito && "El rollback debe restaurar el offset exacto");
    printf("  [PASS] Test 4: arenaSave / arenaRestore ejecuto el Rollback O(1).\n");

    // TEST 5: arenaRealloc In-Place (Agrandar el último bloque)
    size_t tamInicial = 16;
    size_t tamNuevo = 64;

    char* arrayDinamico = (char*) arenaAlloc(&arena, tamInicial);
    arrayDinamico[0] = 'H';
    arrayDinamico[1] = 'O';
    arrayDinamico[2] = 'L';
    arrayDinamico[3] = 'A';

    char* arrayAgrandado = (char*) arenaRealloc(&arena, arrayDinamico, tamInicial, tamNuevo);

    // Como era el ÚLTIMO bloque pedido, debió haberse estirado IN-PLACE (misma dirección)
    assert(arrayAgrandado == arrayDinamico && "Realloc de la ultima asignacion debe ser In-Place");
    assert(arrayAgrandado[0] == 'H' && arrayAgrandado[3] == 'A' && "Los datos originales deben preservarse");
    printf("  [PASS] Test 5: Realloc In-Place optimizado con exito.\n");

    // TEST 6: Reset y Destrucción
    arenaReset(&arena);
    assert(arena.offset == 0 && "Reset debe dejar el offset en 0");
    assert(arenaGetFreeSpace(&arena) == capacidadInicial);

    arenaDestroy(&arena);
    assert(arena.buffer == NULL && "Destroy debe liberar el buffer");
    printf("  [PASS] Test 6: Ciclo de vida destruido correctamente.\n");

    printf("\n  TODOS LOS TESTS PASARON CON ÉXITO. \n");
    return 0;
}