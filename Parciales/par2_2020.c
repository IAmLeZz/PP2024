#include <stdio.h>
//
// Created by Álvaro on 11/9/2024.
//
typedef struct {
    char denominac[25];
    int codig;
    int stock;
    int eliminado;
} artic;

void cargarMenos10(artic articulos[25]) {
    FILE *archivo = fopen("articulos.dat", "rb");
    artic articulosTemp;
    int count = 0;

    while(fread(&articulosTemp, sizeof(artic), 1, archivo)==1) {
        if(articulosTemp.stock < 10 && articulosTemp.eliminado == 0) {
            articulos[count] = articulosTemp;
            count++;

            if (count > 25) {
                break;
            }
        }
    }
    fclose(archivo);

}