//
// Created by Álvaro on 10/19/2024.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUMNOS 100
#define ARCHIVO_ALUMNOS "alumnos.dat"
#define ARCHIVO_ALUMNOS_ORDENADO "alumnos_ordenados.dat"

typedef struct {
    int legajo;
    char apellidoNombre[50];
    int anioIngreso;
    int notaPrimerParcial;
    int notaSegundoParcial;
} Alumno;

// Función para leer el archivo de alumnos en un arreglo de estructuras
int leerArchivoAlumnos(Alumno alumnos[MAX_ALUMNOS]) {
    FILE *archivo = fopen(ARCHIVO_ALUMNOS, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de alumnos.\n");
        exit(1);
    }

    int cantidad = 0;
    // Leemos los alumnos del archivo
    while (fread(&alumnos[cantidad], sizeof(Alumno), 1, archivo)) {
        cantidad++;
    }

    fclose(archivo);
    return cantidad;
}

// Función para escribir el arreglo de alumnos ordenados en un nuevo archivo
void escribirArchivoOrdenado(Alumno alumnos[MAX_ALUMNOS], int cantidad) {
    FILE *archivo = fopen(ARCHIVO_ALUMNOS_ORDENADO, "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo de alumnos ordenados.\n");
        exit(1);
    }

    for (int i = 0; i < cantidad; i++) {
        fwrite(&alumnos[i], sizeof(Alumno), 1, archivo);
    }

    fclose(archivo);
}

// Función para imprimir el contenido del archivo ordenado
void listarArchivoOrdenado() {
    FILE *archivo = fopen(ARCHIVO_ALUMNOS_ORDENADO, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de alumnos ordenados.\n");
        exit(1);
    }

    Alumno alumno;
    printf("\nListado de alumnos ordenados por número de legajo:\n");
    printf("Legajo   Apellido y Nombre            Año Ingreso  Nota 1  Nota 2\n");
    printf("--------------------------------------------------------------\n");

    while (fread(&alumno, sizeof(Alumno), 1, archivo)) {
        printf("%-8d %-30s %-12d %-7d %-7d\n",
               alumno.legajo,
               alumno.apellidoNombre,
               alumno.anioIngreso,
               alumno.notaPrimerParcial,
               alumno.notaSegundoParcial);
    }

    fclose(archivo);
}

// Función de comparación para qsort (orden creciente por número de legajo)
int compararPorLegajo(const void *a, const void *b) {
    Alumno *alumnoA = (Alumno *)a;
    Alumno *alumnoB = (Alumno *)b;
    return (alumnoA->legajo - alumnoB->legajo);
}

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    int cantidadAlumnos = leerArchivoAlumnos(alumnos);

    // Ordenar el arreglo de alumnos por número de legajo
    qsort(alumnos, cantidadAlumnos, sizeof(Alumno), compararPorLegajo);

    // Escribir el archivo ordenado
    escribirArchivoOrdenado(alumnos, cantidadAlumnos);

    // Listar los alumnos del archivo ordenado
    listarArchivoOrdenado();

    return 0;
}
