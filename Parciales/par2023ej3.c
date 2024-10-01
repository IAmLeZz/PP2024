//
// Created by Álvaro on 10/1/2024.
//
#include <stdio.h>
#define MAX 3
float promedioDiagonal(int mat[MAX][MAX]) {
    int suma = 0;
    for (int i = 0; i < MAX; i++) {
        suma += mat[i][MAX-1-i];
    }
    return (float)suma/MAX;
}

void leerMatriz(int mat[MAX][MAX], int filas, int columnas) {
    for(int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor de [%d][%d]", i+1,j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void mostrarMatriz(int mat[MAX][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;
    int mat[MAX][MAX];
    leerMatriz(mat, MAX, MAX);
    mostrarMatriz(mat, MAX, MAX);
    float promedio = promedioDiagonal(mat);
    printf("El promedio es %.2f", promedio);



}