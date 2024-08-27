//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int i, j, esPrimo;

    printf("Numeros primos entre 1 y 100:\n");

    for (i = 2; i <= 100; i++) {
        esPrimo = 1; // Suponemos que el número es primo

        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                esPrimo = 0; // No es primo
                break;
            }
        }

        if (esPrimo) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
