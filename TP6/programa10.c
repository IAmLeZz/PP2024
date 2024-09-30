//
// Created by Álvaro on 9/26/2024.
//
#include <stdio.h>
#define MAX 100

void leerMatriz(int filas, int columnas, int matriz[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor de [%d][%d]", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirCerosPositivosYNegativos(int filas, int columnas, int matriz[MAX][MAX]) {
    int ceros = 0, positivos = 0, negativos = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] > 0) {
                positivos++;
            }
            if (matriz[i][j] < 0){
                negativos++;
            }
            if (matriz[i][j] == 0) {
                ceros++;
            }
        }
    }
    printf("Hay %d ceros, %d positivos y %d negativos", ceros, positivos, negativos);
}

int main() {
    int filas, columnas;
    int matriz[MAX][MAX];

    printf("Cuantas filas debe tener la matriz?: ");
    scanf("%d", &filas);

    printf("Cuantas columnas debe tener la matriz?: ");
    scanf("%d", &columnas);

    leerMatriz(filas, columnas, matriz);
    imprimirCerosPositivosYNegativos(filas, columnas, matriz);
}
