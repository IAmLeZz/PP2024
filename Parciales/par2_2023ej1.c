#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int codig;
    char denominac[25];
    char marca[20];
    int stock;
} artic;

void cambiarMarca() {
    FILE *archivo = fopen("c:\archivos\arts.dat", "rb+");
    artic temp;
    while (fread(&temp, sizeof(artic), 1, archivo)==1) {
        if (strcmp(temp.marca, "Sancor") == 0) {
            strcpy(temp.marca, "Sancor LTD");
            fseek(archivo, -sizeof(artic), SEEK_CUR);
            fwrite(&temp, sizeof(artic), 1, archivo);
        }

    }

    fclose(archivo);
}