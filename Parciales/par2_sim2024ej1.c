//
// Created by Álvaro on 11/13/2024.
//
#include <stdio.h>
#define MAX 100

typedef struct {
    int codig;
    char denominac[25];
    int stock;
} artic;

int verificarSiExiste(artic Arts[MAX], int numArts, int codig) {
    for(int i = 0; i < numArts; i++) {
        if(Arts[i].codig == codig) {
            return 1;
        }
    }
    return 0;

}
int cargarStockMayorQue10(artic Arts[MAX], int numArts) {
    FILE *archivo = fopen("NuevosArts.dat", "rb");

    artic temp;
    while (fread(&temp, sizeof(artic), 1, archivo)==1 ) {
        if (temp.stock > 10 && !verificarSiExiste(Arts, numArts, temp.codig) && numArts < MAX) {
            Arts[numArts] = temp;
            numArts++;
        }
    }
    fclose(archivo);
    return numArts;

}