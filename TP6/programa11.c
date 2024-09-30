//
// Created by Álvaro on 9/26/2024.
//
#include <stdio.h>
#define MAX 100

void leerVector(int filas, int columnas, int matriz[MAX][MAX]) {
    for (int i = 0; i<filas; i++) {
        printf("Ingrese los elementos del vector %d \n", i+1);
        for (int j = 0; j < columnas; j++) {
            printf("Elemento %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

}

void imprimirMatriz(int filas, int columnas, int matriz[MAX][MAX]) {
    printf("Matriz creada: \n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

}

int main() {
    int filas, columnas;
    int matriz[MAX][MAX];

    printf("¿Cuantos vectores quieres tener?: ");
    scanf("%d", &filas);

    printf("¿Cuantos elementos deben tener los vectores?: ");
    scanf("%d", &columnas);

    leerVector(filas, columnas, matriz);
    imprimirMatriz(filas, columnas, matriz);
}