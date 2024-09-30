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
        sumaC = 0;
        for(int i = 0; i < filas; i++) {
            sumaC += matriz[i][j];
        }
        vectorC[j] = sumaC;
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[MAX][MAX]) {
        printf("\n Matriz: \n");
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }

}

void imprimirSumaDeFilasYColumnas(int filas, int columnas, int vectorC[], int vectorF[]) {
    printf("La suma de las filas es\n");
    for(int i = 0; i < filas; i++) {
        printf("Fila %d: %d \n", i+1, vectorF[i]);
    }
    printf("La suma de las columnas es\n");
    for (int j = 0; j < columnas; j++) {
        printf("Columna %d: %d \n", j+1, vectorC[j]);
    }
}
int main() {
    int filas;
    int columnas;
    int matriz[MAX][MAX];
    int sumFilas[MAX];
    int sumColumnas[MAX];

    printf("¿Cuantas filas debe tener la matriz deseada?: ");
    scanf("%d", &filas);
    printf("¿Y cuantas columnas?: ");
    scanf("%d", &columnas);

    leerMatriz(filas, columnas, matriz);
    imprimirMatriz(filas, columnas, matriz);
    sumarFilasYColumnas(filas, columnas, matriz, sumFilas, sumColumnas);
    imprimirSumaDeFilasYColumnas(filas, columnas, sumColumnas, sumFilas);

}