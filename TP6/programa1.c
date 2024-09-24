#include <stdio.h>

#define MAX 100  // Máximo tamaño del vector

// Función para ingresar los datos al vector
void ingresarDatos(int vector[], int *n) {
    do {
        printf("Ingrese la cantidad de elementos (máximo %d): ", MAX);
        scanf("%d", n);
        if (*n > MAX || *n <= 0) {
            printf("Cantidad no válida. Intente nuevamente.\n");
        }
    } while (*n > MAX || *n <= 0);  // Asegurarse de que la cantidad de elementos esté en el rango permitido

    for (int i = 0; i < *n; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

// Función para mostrar los datos del vector
void mostrarVector(int vector[], int n) {
    printf("Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

// Función para ordenar el vector con el metodo de selección
void ordenarSeleccion(int vector[], int n) {
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
        // Intercambiar el elemento mínimo con el primer elemento no ordenado
        aux = vector[i];
        vector[i] = vector[min];
        vector[min] = aux;
    }
    printf("Vector ordenado correctamente.\n");
}

int main() {
    int vector[MAX];  // Declarar el vector con el tamaño máximo
    int n, opcion;
    char continuar;

    do {
        ingresarDatos(vector, &n);  // Ingresar los datos del vector
        mostrarVector(vector, n);  // Mostrar el vector original

        do {
            // Menú para elegir ordenar o salir
            printf("\nSeleccione una opción:\n");
            printf("1. Ordenar el vector\n");
            printf("2. Salir\n");
            scanf("%d", &opcion);

            if (opcion == 1) {
                ordenarSeleccion(vector, n);  // Ordenar el vector
                mostrarVector(vector, n);  // Mostrar el vector ordenado
            } else if (opcion == 2) {
                printf("Saliendo...\n");
            } else {
                printf("Opción no válida. Intente nuevamente.\n");
            }

        } while (opcion != 2);  // Repetir el proceso hasta que el usuario elija salir

        printf("\n¿Desea ingresar un nuevo vector y ordenarlo? (s/n): ");
        scanf(" %c", &continuar);  // Leer la respuesta

    } while (continuar == 's' || continuar == 'S');  // Continuar si el usuario desea hacerlo nuevamente

    printf("Programa finalizado.\n");
    return 0;
}
