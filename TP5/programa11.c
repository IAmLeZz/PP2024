//
// Created by Álvaro on 9/14/2024.
//
#include <stdio.h>

// Función para leer una matriz desde el teclado
void leerMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para sumar dos matrices
void sumarMatrices(int filas, int columnas, int matrizA[filas][columnas], int matrizB[filas][columnas], int resultado[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

// Función para imprimir una matriz
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int matrizA[filas][columnas];
    int matrizB[filas][columnas];
    int resultado[filas][columnas];

    printf("Ingrese los elementos de la primera matriz:\n");
    leerMatriz(filas, columnas, matrizA);

    printf("Ingrese los elementos de la segunda matriz:\n");
    leerMatriz(filas, columnas, matrizB);

    sumarMatrices(filas, columnas, matrizA, matrizB, resultado);

    printf("La suma de las matrices es:\n");
    imprimirMatriz(filas, columnas, resultado);

    return 0;
}
