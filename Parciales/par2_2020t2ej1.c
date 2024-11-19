//
// Created by Álvaro on 11/10/2024.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 25

typedef struct {
    int codig;
    char denominac[MAX];
    int stock;
} artic;

void cargarStockMayor10(artic articulos[MAX]) {
    FILE *archivo = fopen("articulos.dat", "rb");
    if (archivo == NULL) {
        printf("No existe el archivo. \n");
        exit(400);
    }
    artic temp;

    int count = 0;
    while (fread(&temp, sizeof(artic), 1, archivo)==1 && count<MAX) {
        if (temp.stock>10) {
            articulos[count] = temp;
            count++;
        }
    }

    fclose(archivo);

    for(int i = 0; i < count; i++) {
        for (int j = 0; j < count-1; j++) {
            if (articulos[j].codig>articulos[j+1].codig) {
                temp = articulos[j];
                articulos[j] = articulos[j+1];
                articulos[j+1] = temp;
            }
        }
    }
}