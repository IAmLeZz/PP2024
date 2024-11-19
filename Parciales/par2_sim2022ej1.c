//
// Created by Álvaro on 11/14/2024.
//
#include <stdio.h>
#define MAX 100

typedef struct {
    int codig;
    char denominac[25];
    int stock;
} artic;

int verificarSiExiste(artic Arts[MAX], int numArts, int codigo) {
    for(int i = 0; i < numArts; i++) {
        if (Arts[i].codig == codigo) {
            return 1;
        }
    }
    return 0;
}

int cargarArts(artic Arts[MAX], int numArts) {
    FILE *archivo = fopen("articulos.dat", "rb");

    artic temp;

    while (fread(&temp, sizeof(artic), 1, archivo)==1 && verificarSiExiste(Arts, numArts, temp.codig) && numArts < MAX) {
        if (temp.stock>10) {
            Arts[numArts] = temp;
            numArts++;
        }
    }
    return numArts;
}