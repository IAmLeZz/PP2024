//
// Created by Álvaro on 9/30/2024.
//
#include <stdio.h>
#define MAX 100

void crearMatriz(int vector1[MAX], int vector2[MAX], int vector3[MAX], int matriz[MAX][3]) {
    for(int i = 0; i < MAX; i++) {
        matriz[i][0] = vector1[i];
        matriz[i][1] = vector2[i];
        matriz[i][2] = vector3[i];
    }
}

void mostrarMatriz(int matriz[MAX][3]) {
    for(int i = 0; i < MAX; i++) {
        printf("%d\t%d\t%d\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }
}

int main() {
    int vector1[MAX];
    int vector2[MAX];
    int vector3[MAX];
    int matriz[MAX][3];

    for(int i = 0; i < MAX; i++) {
        vector1[i] = i+1;
        vector2[i] = i+101;
        vector3[i] = i+201;
    }

    crearMatriz(vector1, vector2, vector3, matriz);
    mostrarMatriz(matriz);



}