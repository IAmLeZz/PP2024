//
// Created by Álvaro on 9/29/2024.
//
#include <stdio.h>
#define FILS 10
#define COLS 10

void leerMatriz(int mat[FILS][COLS], int filas, int columnas) {
    for(int i = 0; i<filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("Ingrese el valor de [%d][%d]", i+1,j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

float promFil(int mat[FILS][COLS], int fila, int columnas) {
    int suma = 0;
    for (int j = 0; j < columnas; j++) {
       suma += mat[fila][j];
    }
    float promedio = (float)suma/columnas;
    return promedio;
}

int main() {
    int mat[FILS][COLS];
    int fila, filas, columnas;
    printf("De cuantas filas debe ser la matriz?: \n");
    scanf("%d", &filas);
    printf("De cuantas columnas debe ser la matriz?: \n");
    scanf("%d", &columnas);
    leerMatriz(mat, filas, columnas);

    printf("Ingrese el numero de la fila para calcular el promedio (0 a %d): ", filas - 1);
    scanf("%d", &fila);
    float prom = promFil(mat, fila, columnas);

    printf("El promedio de la fila %d es %.2f", fila, prom);

}