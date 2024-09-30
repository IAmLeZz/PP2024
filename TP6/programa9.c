//
// Created by Álvaro on 9/25/2024.
//
#include <stdio.h>
#define MAX 100

void leerMatriz(int filas, int columnas, int matriz[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void crearVectores(int filas, int columnas, int matriz[MAX][MAX]) {
    for(int i = 0; i < filas; i++) {
        printf("Vector %d: ", i+1);
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int filas, columnas;
    int matriz[MAX][MAX];

    printf("De cuantas filas debe ser la matriz?: \n");
    scanf("%d", &filas);

    printf("De cuantas columnas debe ser la matriz?: \n");
    scanf("%d", &columnas);

    leerMatriz(filas, columnas, matriz);
    crearVectores(filas, columnas, matriz);



}
