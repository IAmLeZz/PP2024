//
// Created by Álvaro on 10/19/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 100
#define APROBADO 40
#define ARCHIVO_ALUMNOS "alumnos.dat"

typedef struct {
    int legajo;
    char apellidoNombre[50];
    int anioIngreso;
    int notaPrimerParcial;
    int notaSegundoParcial;
} Alumno;

// Función para crear el archivo de alumnos inicial sin notas de parciales
void crearArchivoAlumnos() {
    FILE *archivo = fopen(ARCHIVO_ALUMNOS, "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        exit(1);
    }

    int cantidad;
    Alumno alumno;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &cantidad);
    getchar();  // Limpiar el buffer

    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el número de legajo: ");
        scanf("%d", &alumno.legajo);
        getchar();  // Limpiar el buffer

        printf("Ingrese el apellido y nombre: ");
        fgets(alumno.apellidoNombre, 50, stdin);
        alumno.apellidoNombre[strcspn(alumno.apellidoNombre, "\n")] = 0;  // Eliminar el salto de línea

        printf("Ingrese el año de ingreso: ");
        scanf("%d", &alumno.anioIngreso);

        // Inicializamos las notas en -1 para indicar que aún no se ingresaron.
        alumno.notaPrimerParcial = -1;
        alumno.notaSegundoParcial = -1;

        fwrite(&alumno, sizeof(Alumno), 1, archivo);
    }

    fclose(archivo);
}

// Función para ingresar las notas de los alumnos
void ingresarNotas() {
    FILE *archivo = fopen(ARCHIVO_ALUMNOS, "rb+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    Alumno alumno;
    printf("Ingresar notas de los alumnos:\n");

    // Leemos todos los alumnos del archivo
    while (fread(&alumno, sizeof(Alumno), 1, archivo)) {
        printf("\nAlumno: %s (Legajo: %d)\n", alumno.apellidoNombre, alumno.legajo);

        printf("Ingrese la nota del primer parcial: ");
        scanf("%d", &alumno.notaPrimerParcial);

        printf("Ingrese la nota del segundo parcial: ");
        scanf("%d", &alumno.notaSegundoParcial);

        // Movemos el puntero del archivo atrás para sobreescribir la estructura
        fseek(archivo, -sizeof(Alumno), SEEK_CUR);
        fwrite(&alumno, sizeof(Alumno), 1, archivo);

        // Aseguramos mover el puntero al siguiente alumno
        fseek(archivo, 0, SEEK_CUR);
    }

    fclose(archivo);
}

// Función para listar alumnos aprobados en un parcial específico
void listarAprobados(int parcial) {
    FILE *archivo = fopen(ARCHIVO_ALUMNOS, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    Alumno alumno;
    printf("\nListado de alumnos aprobados (parcial %d):\n", parcial);
    printf("Apellido y Nombre            Nota\n");
    printf("-----------------------------------\n");

    // Recorremos los alumnos en el archivo
    while (fread(&alumno, sizeof(Alumno), 1, archivo)) {
        int nota = (parcial == 1) ? alumno.notaPrimerParcial : alumno.notaSegundoParcial;
        if (nota >= APROBADO) {
            printf("%-30s %d\n", alumno.apellidoNombre, nota);
        }
    }

    fclose(archivo);
}


// Función para listar alumnos desaprobados en un parcial específico
void listarDesaprobados(int parcial) {
    FILE *archivo = fopen(ARCHIVO_ALUMNOS, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    Alumno alumno;
    printf("\nListado de alumnos desaprobados (parcial %d):\n", parcial);
    printf("Apellido y Nombre            Nota\n");
    printf("-----------------------------------\n");

    // Recorremos los alumnos en el archivo
    while (fread(&alumno, sizeof(Alumno), 1, archivo)) {
        int nota = (parcial == 1) ? alumno.notaPrimerParcial : alumno.notaSegundoParcial;
        if (nota < APROBADO) {
            printf("%-30s %d\n", alumno.apellidoNombre, nota);
        }
    }

    fclose(archivo);
}

int main() {
    int opcion;
    int parcial;

    do {
        printf("\nMenú de opciones:\n");
        printf("1. Crear archivo de alumnos\n");
        printf("2. Ingresar notas\n");
        printf("3. Listar aprobados\n");
        printf("4. Listar desaprobados\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearArchivoAlumnos();
            break;
            case 2:
                ingresarNotas();
            break;
            case 3:
                printf("Seleccione el parcial (1 o 2): ");
            scanf("%d", &parcial);
            listarAprobados(parcial);
            break;
            case 4:
                printf("Seleccione el parcial (1 o 2): ");
            scanf("%d", &parcial);
            listarDesaprobados(parcial);
            break;
            case 5:
                printf("Saliendo del programa.\n");
            break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}