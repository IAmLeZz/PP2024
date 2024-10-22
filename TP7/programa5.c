//
// Created by Álvaro on 10/14/2024.
//
#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct {
    int cantidadAutores;
    char nombreAutores[10][30];
} autor;

typedef struct {
    char titulo[30];
    autor autorLibro;
    char nombreEditorial [30];
    int añoPublicacion;
    int numCatalogo;
} libro;

void leerLibro(libro libros[MAX], int ce) {
    for(int i = 0; i < ce; i++) {
        printf("¿Cual es el nombre del libro?: \n");
        gets(libros[i].titulo);
        printf("¿Cual es la cantidad de autores?: \n");
        scanf("%d", &libros[i].autorLibro.cantidadAutores);
        getchar();
        for(int j = 0; j < libros[i].autorLibro.cantidadAutores; j++) {
            printf("Introduce el nombre del autor %d: \n", j+1);
            fgets(libros[i].autorLibro.nombreAutores[j], 30, stdin);
            libros[i].autorLibro.nombreAutores[j][strcspn(libros[i].autorLibro.nombreAutores[j], "\n")] = '\0';
        }
        printf("Cual es el nombre de la editorial?: \n");
        gets(libros[i].nombreEditorial);
        printf("Cual es el año de publicacion?: \n");
        scanf("%d", &libros[i].añoPublicacion);
        getchar();
        printf("Cual es el num de catalogo? \n");
        scanf("%d", &libros[i].numCatalogo);
        getchar();

    }
}
void imprimirLibros(libro libros[], int ce) {
    for (int i = 0; i < ce; i++) {
        printf("Libro %d:\n", i + 1);
        printf("Título: %s\n", libros[i].titulo);
        printf("Editorial: %s\n", libros[i].nombreEditorial);
        printf("Año de publicación: %d\n", libros[i].añoPublicacion);
        printf("Número de catálogo: %d\n", libros[i].numCatalogo);
        printf("Autores:\n");
        for (int j = 0; j < libros[i].autorLibro.cantidadAutores; j++) {
            printf(" - %s\n", libros[i].autorLibro.nombreAutores[j]);
        }
        printf("\n");
    }
}

void ordenarPorAño(libro libros[MAX], int ce) {
    int i, j;
    libro aux;
    for(i = 0; i < ce; i++){
        for(j = 0; j < ce-1; j++) {
            if (libros[j].añoPublicacion > libros[j+1].añoPublicacion) {
                aux = libros[j];
                libros[j] = libros[j+1];
                libros[j+1] = aux;
            }
        }
    }
}

void buscarAutor(libro libros[MAX], char autor[30], int ce) {
    int j = 0, encontrado = 0;
    for(int i = 0; i < ce; i++) {
        while(j < libros[i].autorLibro.cantidadAutores && encontrado == 0) {
            if(strcmp(autor, libros[i].autorLibro.nombreAutores[j]) == 0) {
                printf("- %s\n", libros[i].titulo);
                encontrado = 1;
            }
            j++;
        }
    }
    if (!encontrado) {
        printf("No se encontró ningun libro de ese autor. \n");
    }
}

void buscarEditorial(libro libros[MAX], char editorial[30], int ce) {
    int i= 0, j=0, encontrado = 0;
    while(i<ce && encontrado == 0) {
        if (strcmp(libros[i].nombreEditorial, editorial) == 0) {
            printf("- %s\n", libros[i].titulo);
            encontrado = 1;
        }
        i++;
    }
    if (!encontrado) {
        printf("No se encontró ningun libro de esa editorial. \n");
    }
}

void imprimirCatalogo(libro libros[MAX], int numCat1, int numCat2, int ce) {
    int encontrado = 0;
    for(int i = 0; i < ce; i++) {
        if (libros[i].numCatalogo >= numCat1 && libros[i].numCatalogo <= numCat2) {
            printf("- %s (numero de catalogo %d) \n", libros[i].titulo, libros[i].numCatalogo);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontro ningun libro en ese rango de catalogo \n");
    }
}

int main() {
    libro libros[MAX] = {
        {"Libro 1", {2, {"Autor1", "Autor2"}}, "Editorial1", 2005, 1001},
        {"Libro 2", {1, {"Autor3"}}, "Editorial2", 1999, 1002},
        {"Libro 3", {3, {"Autor4", "Autor5", "Autor6"}}, "Editorial3", 2015, 1003},
        {"Libro 4", {1, {"Autor7"}}, "Editorial4", 2010, 1004}
    };

    int ce = 4;
    char editorialBuscada[30];
    char autorBuscado[30];
    int minCatalogo, maxCatalogo;
    /*
    printf("Cuantos libros son? \n");
    scanf("%d", &ce);
    getchar();

    leerLibro(libros, ce);
    */
    imprimirLibros(libros, ce);
    ordenarPorAño(libros, ce);
    printf("Libros ordenados por año, de menor a mayor: \n");

    imprimirLibros(libros, ce);
    printf("Ingrese el nombre del autor a buscar: ");
    gets(autorBuscado);
    buscarAutor(libros, autorBuscado, ce);

    printf("Ingrese el nombre de la editorial a buscar: ");
    gets(editorialBuscada);
    buscarEditorial(libros, editorialBuscada, ce);


    printf("Ingrese el número mínimo de catálogo: ");
    scanf("%d", &minCatalogo);
    printf("Ingrese el número máximo de catálogo: ");
    scanf("%d", &maxCatalogo);

    imprimirCatalogo(libros,minCatalogo, maxCatalogo, ce);


}
