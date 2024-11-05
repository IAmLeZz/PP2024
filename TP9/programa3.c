//
// Created by Álvaro on 11/3/2024.
//
#include <stdio.h>
#define TAM 100

void concatenar(const char *s1, const char *s2, char *s3) {
    if (*s1 != '\0') {
        *s3 = *s1;
        concatenar(s1+1, s2, s3+1);
    } else if (*s2 != '\0') {
        *s3 = *s2;
        concatenar(s1, s2+1, s3+1);
    } else {
        *s3 = '\0';
    }
}

int main() {
    char texto1[TAM];
    char texto2[TAM];
    char texto3[TAM];

    printf("Cual es el texto 1? \n");
    gets(texto1);
    printf("Cual es el texto 2? \n");
    gets(texto2);

    concatenar(texto1, texto2, texto3);
    printf("Resultado de concatenar %s \n", texto3);

    return 0;
}