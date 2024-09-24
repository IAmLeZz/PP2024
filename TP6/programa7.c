//
// Created by Álvaro on 9/24/2024.
//

#include <stdio.h>
#define MAX 100

void leerMatriz(int filas, int columnas, int matriz[MAX][MAX], char nombre) {
    printf("Ingrese los elementos de la matriz %c", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingresa el valor de [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void sumarMatrices( int filas, int columnas, int matrizA[MAX][MAX], int matrizB[MAX][MAX], int matrizC[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}
void imprimirMatriz(int filas, int columnas, int matriz[MAX][MAX], char nombre) {
    printf("La matriz %c es \n", nombre);
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j<columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int filas;
    int columnas;
    int matrizA[MAX][MAX];
    int matrizB[MAX][MAX];
    int matrizC[MAX][MAX];

    printf("Ingresa la cantidad de filas de las matrices: ");
    scanf("%d", &filas);
    printf("Ingresa la cantidad de columnas de las matrices: ");
    scanf("%d", &columnas);

    leerMatriz(filas, columnas, matrizA, "A");
    leerMatriz(filas, columnas, matrizB, "B");

    sumarMatrices(filas, columnas, matrizA, matrizB, matrizC);
    imprimirMatriz(filas, columnas, matrizA, "A");
    imprimirMatriz(filas, columnas, matrizB, "B");
    imprimirMatriz(filas, columnas, matrizC, "C");

    return 0;
}