//
// Created by Álvaro on 9/14/2024.
//
#include <stdio.h>

void leerMatriz(int dimension, int matriz[dimension][dimension]) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para calcular la transpuesta de una matriz cuadrada
void transponerMatriz(int dimension, int matriz[dimension][dimension]) {
    for (int i = 0; i < dimension; i++) {
        for (int j = i + 1; j < dimension; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}

void imprimirMatriz(int dimension, int matriz[dimension][dimension]) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int dimension;

    printf("Ingrese la dimensión de la matriz cuadrada: ");
    scanf("%d", &dimension);

    int matriz[dimension][dimension];

    printf("Ingrese los elementos de la matriz:\n");
    leerMatriz(dimension, matriz);

    printf("La matriz original es:\n");
    imprimirMatriz(dimension, matriz);

    transponerMatriz(dimension, matriz);

    printf("La matriz transpuesta es:\n");
    imprimirMatriz(dimension, matriz);

    return 0;
}
