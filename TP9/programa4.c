//
// Created by Álvaro on 11/3/2024.
//
#include <stdio.h>
#include <string.h>
#define TAM 100

int posicionCaracter(char texto[TAM], int i, char c) {
    if (texto[i] == c) {
        return i;
    }
    if (i>strlen(texto)) {
        return -1;
    }
    posicionCaracter(texto, i+1, c);
}


int main() {
    char texto[TAM], c;
    int pos = 0, i = 0;

    printf("Ingrese el texto \n");
    gets(texto);
    printf("Ingrese el caracter a buscar \n");
    scanf("%c", &c);

    pos = posicionCaracter(texto, i, c);
    printf("La posicion es %d. Si es -1 es porque no existe.", pos);



}