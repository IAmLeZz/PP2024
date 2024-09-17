//
// Created by Álvaro on 9/14/2024.
//
#include <stdio.h>
#include <stdbool.h>

// Función para leer una matriz desde el teclado
void leerMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para buscar un valor en una matriz
bool buscarValor(int filas, int columnas, int matriz[filas][columnas], int valor) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == valor) {
                return true;
            }
        }
    }
    return false;
}

// Función para imprimir las posiciones de un valor en una matriz
void imprimirPosiciones(int filas, int columnas, int matriz[filas][columnas], int valor) {
    printf("Posiciones del valor %d:\n", valor);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == valor) {
                printf("Fila %d, Columna %d\n", i, j);
            }
        }
    }
}

int main() {
    int filas, columnas, valor;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    printf("Ingrese los elementos de la matriz:\n");
    leerMatriz(filas, columnas, matriz);

    printf("Ingrese el valor a buscar: ");
    scanf("%d", &valor);

    if (buscarValor(filas, columnas, matriz, valor)) {
        printf("El valor %d se encuentra en la matriz.\n", valor);
        imprimirPosiciones(filas, columnas, matriz, valor);
    } else {
        printf("El valor %d no se encuentra en la matriz.\n", valor);
    }

    return 0;
}
