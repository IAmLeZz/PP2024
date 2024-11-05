//
// Created by Álvaro on 11/3/2024.
//
#include <stdio.h>
#define TAM 200

void eliminarEspacios(char *texto) {
    if (*texto=='\0') {
        return;
    }
    if (*texto == ' ') {
        char *temp = texto;
        while (*temp != '\0') {
            *temp = *(temp+1);
            temp++;
        }
        eliminarEspacios(texto);

    } else {
        eliminarEspacios(texto+1);
    }
}


int main() {
    char texto[TAM];
    printf("Ingrese el texto. \n");
    gets(texto);
    eliminarEspacios(texto);
    printf("%s", texto);

}