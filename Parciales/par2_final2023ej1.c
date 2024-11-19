//
// Created by Álvaro on 11/19/2024.
//
#include <iso646.h>
#include <stdio.h>
#define MAX 100

typedef struct {
    int codig;
    int stock;
    char denominac[25];
} artic;

void cargarYOrdenar(artic articulos[MAX]) {
    FILE *archivo = fopen("articulos.dat", "rb");
    artic temp;
    int count = 0, i = 1, j=0, ordenado = 0;
    while (fread(&temp, sizeof(artic), 1,archivo)==1) {
        if (temp.stock>10) {
            articulos[count] = temp;
            count++;
        }
    }
    fclose(archivo);

    while (i<count && ordenado == 0) {
        ordenado = 1;
        for(j = 0; j < count-i; j++) {
            if (articulos[j].codig>articulos[j+1].codig) {
                ordenado = 0;
                temp = articulos[j];
                articulos[j] = articulos[j+1];
                articulos[j+1] = temp;
            }
        }
        i++;
    }
}