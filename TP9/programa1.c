//
// Created by Álvaro on 11/3/2024.
//
#include <stdio.h>
#define TAM 100
int devolverCantCaracteres(char texto[TAM], int e) {
    int cont = 0;
    if (texto[e]!='\0'&&e<TAM) {
        e++;
        cont++;
        cont =cont+devolverCantCaracteres(texto, e);
    }
    return cont;

}

int main() {
    char texto[TAM];
    int cant = 0, e = 0;

    printf("Ingrese el texto. Max 200 caracteres \n");
    gets(texto);
    printf("Ingresó %s \n", texto);
    cant = devolverCantCaracteres(texto, e);
    printf("El texto tiene %d caracteres \n", cant);
}