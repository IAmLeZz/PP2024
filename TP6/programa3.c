//
// Created by Álvaro on 9/22/2024.
//
#include <stdio.h>

// Función para ingresar los datos en el arreglo
void ingresarDatos(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

// Función para mostrar el arreglo
void mostrarVector(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

// Función para ordenar el arreglo utilizando el método burbuja optimizado
void ordenarBurbujaOptimizado(int vector[], int n) {
    int i, j, aux;
    int ordenado;  // Variable de control para verificar si el arreglo ya está ordenado

    for (i = 0; i < n - 1; i++) {
        ordenado = 1;  // Suponer que el arreglo está ordenado

        for (j = 0; j < n - 1 - i; j++) {
            if (vector[j] > vector[j + 1]) {
                // Intercambiar los elementos si están en el orden incorrecto
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;

                ordenado = 0;  // Se realizó un intercambio, por lo tanto, no está ordenado
            }
        }

        // Si no se realizaron intercambios, el arreglo está ordenado
        if (ordenado) {
            break;
        }
    }
}

int main() {
    int n;

    // Solicitar al usuario la cantidad de elementos del vector
    printf("Ingrese la cantidad de elementos del vector: ");
    scanf("%d", &n);

    int vector[n];

    // Ingresar los datos del vector
    ingresarDatos(vector, n);

    // Mostrar el vector original
    printf("\nVector original: ");
    mostrarVector(vector, n);

    // Ordenar el vector usando el método burbuja optimizado
    ordenarBurbujaOptimizado(vector, n);

    // Mostrar el vector ordenado
    printf("\nVector ordenado: ");
    mostrarVector(vector, n);

    return 0;
}
