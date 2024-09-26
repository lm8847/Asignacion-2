#include <stdio.h>
#include <string.h>

#define MEM_SIZE 100 // Tamaño de la memoria

#define CODE_SEG_SIZE 30  // Segmento de código
#define DATA_SEG_SIZE 30  // Segmento de datos
#define STACK_SEG_SIZE 20 // Segmento de pila
#define HEAP_SEG_SIZE 20  // Segmento de montón

char memoria[MEM_SIZE]; 

struct MemSegment {
    int inicio;
    int tamano;
};

struct MemSegment codigo = {0, CODE_SEG_SIZE};     
struct MemSegment datos = {30, DATA_SEG_SIZE};     
struct MemSegment pila = {60, STACK_SEG_SIZE};     
struct MemSegment heap = {80, HEAP_SEG_SIZE};      

void ejecutarInstruccion(char* instruccion) {
    if (strcmp(instruccion, "LOAD") == 0) {
        memoria[datos.inicio] = 10; 
    } else if (strcmp(instruccion, "ADD") == 0) {
        memoria[datos.inicio] += 5;
    } else if (strcmp(instruccion, "SUB") == 0) {
        memoria[datos.inicio] -= 3;
    } else if (strcmp(instruccion, "STORE") == 0) {
        memoria[pila.inicio] = memoria[datos.inicio]; 
    } else if (strcmp(instruccion, "HALT") == 0) {
        // Detener el programa
    }
}

void mostrarMemoria() {
    printf("\n--- Distribución de la Memoria ---\n");
    printf("Segmento de Código: desde %d hasta %d\n", codigo.inicio, codigo.inicio + codigo.tamano - 1);
    printf("Segmento de Datos: desde %d hasta %d\n", datos.inicio, datos.inicio + datos.tamano - 1);
    printf("Segmento de Pila: desde %d hasta %d\n", pila.inicio, pila.inicio + pila.tamano - 1);
    printf("Segmento de Montón: desde %d hasta %d\n", heap.inicio, heap.inicio + heap.tamano - 1);
}

int main() {
    FILE *archivo;
    char instruccion[10];

    mostrarMemoria();

    archivo = fopen("programa.txt", "r");  

    if (archivo == NULL) {
        return 1;
    }

    while (fgets(instruccion, 10, archivo) != NULL) {
        instruccion[strcspn(instruccion, "\n")] = '\0';
        ejecutarInstruccion(instruccion);  
    }

    fclose(archivo);
    return 0;
}
