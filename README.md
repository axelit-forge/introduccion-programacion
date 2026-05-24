# Introducción a la Programación (UNSa)

Proyectos y laboratorios desarrollados en C nativo durante el primer año de la carrera (2024). Sirve como registro de mi base en programación estructurada, lógica algorítmica y modularización elemental.

##Contenido actual
Los trabajos están agrupados por la lógica de las unidades:
* **Unidades 1 a 3 (Lógica básica):** Estructuras secuenciales, condicionales y bucles.
* **Unidades 4 y 5 (Arreglos):** Vectores, matrices y uso de la librería `string.h`.
* **Unidades 6 y 7 (Modularización):** Manejo de funciones, punteros y Tipos Abstractos de Datos (TADs).

## Próximos pasos (Roadmap)
La prioridad actual del portfolio es el mantenimiento del simulador de autómatas (C) y la corrección de dependencias/duplicados en el repositorio de estructuras de datos (Java). Una vez finalizado, se integrará a este repositorio un bloque de ingeniería de bajo nivel:

* **Modelos de Exámenes:** Resolución de parciales clásicos de la cátedra.
* **Listas intrusivas:** Estructuras con nodos embebidos en el dato (estilo kernel de Linux) usando macros para el cálculo de offsets (`container_of`).
* **Arena Allocator:** Gestión de memoria lineal en bloque para reducir fragmentación y evitar el overhead de `malloc`/`free`.
* **Fixed-Size Memory Pool:** Asignación rápida para objetos del mismo tamaño.
* **Bitmaps & Bitsets:** Operaciones de conjuntos mediante manipulación de bits pura (`&`, `|`, `~`, `<<`).
* **Ring Buffer:** Implementación de buffer circular para flujo eficiente de datos.

## Entorno y compilación
* **IDES:** CLion / Terminal 
* **OS/Compilador:** GCC sobre WSL2 (Ubuntu).
* **Build:** Los proyectos modulares usan CMake. Los archivos sueltos se compilan directo por terminal (algunos requeriran la libreria Math asi que se recomienda mirar los archivos fuentes antes de compilarlos):

```bash
gcc archivo.c -o test.out && ./test.out
