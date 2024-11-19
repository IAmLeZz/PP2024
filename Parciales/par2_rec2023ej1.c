#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int codig;
    char denominac[25];
    char marca[25];
    int stock;
    double prevta;
    int eliminado;
} artic;

void aumentarArticulos(char marcaElegida[25]) {
    FILE *archivo = fopen("articulos.dat", "rb+");

    artic temp;
    while (fread(&temp, sizeof(artic), 1, archivo)==1 && temp.eliminado == 0) {
        if (strcmp(temp.marca, marcaElegida)==0) {
            temp.prevta = temp.prevta * 1.20;
        }
        fseek(archivo, -sizeof(artic), SEEK_CUR);
        fwrite(&temp, sizeof(artic), 1, archivo);
    }
    fclose(archivo);
}