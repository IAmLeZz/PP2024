//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>
#include <stdbool.h>

// Función que determina si un número es primo
bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Función que imprime todos los números primos en un rango dado
void imprimirPrimosEnRango(int min, int max) {
    printf("Números primos entre %d y %d:\n", min, max);
    for (int i = min; i <= max; i++) {
        if (esPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int min, max;

    printf("Ingrese el valor mínimo del rango: ");
    scanf("%d", &min);
    printf("Ingrese el valor máximo del rango: ");
    scanf("%d", &max);

    imprimirPrimosEnRango(min, max);

    return 0;
}
