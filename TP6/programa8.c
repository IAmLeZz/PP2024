//
// Created by Álvaro on 9/24/2024.
//
#include <stdio.h>
#define MAX 100

void leerMatriz(int filas, int columnas, int matriz[MAX][MAX]) {
    for(int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

}

void sumarFilasYColumnas(int filas, int columnas, int matriz[MAX][MAX], int vectorF[], int vectorC[]) {
    int sumaF=0, sumaC = 0;
    for (int i = 0; i<filas; i++) {
        sumaF = 0;
        for(int j = 0; j < columnas; j++) {
            sumaF += matriz[i][j];
        }
        vectorF[i] = sumaF;
    }
    for (int j = 0; j<columnas;j++) {

    }
}

int main() {
    int filas;
    int columnas;
    int matriz[MAX][MAX];
    int sumFilas[];
    int sumColumnas[];

    printf("¿Cuantas filas debe tener la matriz deseada?: ");
    scanf("%d", &filas);
    printf("¿Y cuantas columnas?: ");
    scanf("%d", &columnas);

    leerMatriz(filas, columnas, matriz);

}