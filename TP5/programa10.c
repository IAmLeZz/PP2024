//
// Created by Álvaro on 9/13/2024.
//
#include <stdio.h>

int main() {
    int numeros[10];
    int posiciones[10];

    printf("Ingrese los 10 números de la lotería:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        posiciones[i] = i + 1;
    }

    printf("\nPosición  Número\n");
    for (int i = 0; i < 10; i++) {
        printf("%-9d %d\n", posiciones[i], numeros[i]);
    }

    return 0;
}
