//
// Created by Álvaro on 12/16/2024.
//
#include <stdio.h>

typedef struct {
    int codig;
    char denominac[25];
    int stock;
    int eliminado;
} artic;

int existeCodigo(FILE *archivo, int codigo) {
    artic temp;
    rewind(archivo);
    while (fread(&temp , sizeof(artic), 1, archivo)== 1) {
        if (temp.codig== codigo && temp.eliminado == 0) {
            return 1;
        }
    }
    return 0;
}

void agregarElementos() {
    FILE *archivo = fopen("archivos.dat", "rb+");
    artic nuevoArticulo, temp;
    int encontrado = 0;

    printf("Ingrese el código del articulo \n");
    scanf("%d", &nuevoArticulo.codig);

    if (existeCodigo("archivos.dat", nuevoArticulo.codig)) {
        printf("El código ya existe.");
        fclose(archivo);
    }
    printf("Ingrese el stock del nuevo articulo \n");
    scanf("%d", &nuevoArticulo.stock);
    getchar();
    printf("Ingrese el nombre del archivo. \n");
    gets(nuevoArticulo.denominac);

    nuevoArticulo.eliminado = 0;

    rewind(archivo);

    while (fread(&temp, sizeof(artic), 1, archivo)==1 && encontrado == 0) {
        if (temp.eliminado == 1) {
            fseek(archivo, -sizeof(artic), SEEK_CUR);
            fwrite(&temp, sizeof(artic), 1, archivo);
            printf("Articulo agregado en hueco eliminado. \n");
            encontrado = 1;

        }
    }
    if (!encontrado) {
        fwrite(&temp, sizeof(artic), 1, archivo);
        printf("Articulo añadido al final. \n");
    }
    fclose(archivo);
}
