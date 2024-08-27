//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int numero, ultimoDigito;

    printf("Introduce un numero entero: ");
    scanf("%d", &numero);

    // Calcular el último dígito
    ultimoDigito = numero % 10;

    // Determinar si es par o impar
    if (numero % 2 == 0) {
        printf("El numero %d es par.\n", numero);
    } else {
        printf("El numero %d es impar.\n", numero);
    }

    printf("El último digito es: %d\n", ultimoDigito);

    return 0;
}