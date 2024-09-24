//
// Created by Álvaro on 9/22/2024.
//
#include <stdio.h>

#define MAX 100  // Tamaño máximo para los vectores

// Función para ingresar los elementos de un vector
void ingresarDatos(int vector[], int n, char nombre) {
    printf("\nIngrese los elementos del vector %c:\n", nombre);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

// Función para mostrar un vector
void mostrarVector(int vector[], int n, char nombre) {
    printf("\nVector %c ordenado: ", nombre);
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

// Función para ordenar un vector utilizando el método burbuja
void ordenarBurbuja(int vector[], int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

// Función para mezclar dos vectores ordenados en un tercero también ordenado
void mezclarVectores(int v1[], int n, int v2[], int m, int v3[]) {
    int i = 0, j = 0, k = 0;

    // Comparar y mezclar elementos de ambos vectores
    while (i < n && j < m) {
        if (v1[i] < v2[j]) {
            v3[k++] = v1[i++];
        } else {
            v3[k++] = v2[j++];
        }
    }

    // Añadir los elementos restantes del primer vector si hay
    while (i < n) {
        v3[k++] = v1[i++];
    }

    // Añadir los elementos restantes del segundo vector si hay
    while (j < m) {
        v3[k++] = v2[j++];
    }
}

int main() {
    int n, m;
    int vector1[MAX], vector2[MAX], vectorMezclado[MAX * 2];  // Vectores

    // Ingresar la cantidad de elementos del vector 1
    printf("Ingrese la cantidad de elementos del vector A: ");
    scanf("%d", &n);
    ingresarDatos(vector1, n, 'A');

    // Ingresar la cantidad de elementos del vector 2
    printf("Ingrese la cantidad de elementos del vector B: ");
    scanf("%d", &m);
    ingresarDatos(vector2, m, 'B');

    // Ordenar los dos vectores por el método burbuja
    ordenarBurbuja(vector1, n);
    ordenarBurbuja(vector2, m);

    // Mostrar los vectores ya ordenados
    mostrarVector(vector1, n, 'A');
    mostrarVector(vector2, m, 'B');

    // Mezclar los dos vectores ordenados en un tercero
    mezclarVectores(vector1, n, vector2, m, vectorMezclado);

    // Mostrar el vector resultante de la mezcla
    printf("\nVector C resultante de la mezcla: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", vectorMezclado[i]);
    }
    printf("\n");

    return 0;
}
