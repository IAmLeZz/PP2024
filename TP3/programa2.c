//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int numero, pares = 0, impares = 0;

    printf("Introduce numeros enteros (introduce 0 para terminar):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (numero % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    printf("Cantidad de numeros pares: %d\n", pares);
    printf("Cantidad de numeros impares: %d\n", impares);

    return 0;
}
