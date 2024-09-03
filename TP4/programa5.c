//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>

// Función que calcula el factorial de un número entero positivo
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // El factorial de 0 y 1 es 1
    } else {
        return n * factorial(n - 1); // Llamada recursiva
    }
}

int main() {
    int numero;

    // Solicitar al usuario que ingrese un número entero positivo
    printf("Introduce un número entero positivo: ");
    scanf("%d", &numero);

    // Verificar que el número sea positivo
    if (numero < 0) {
        printf("El numero debe ser entero y positivo.\n");
    } else {
        printf("El factorial de %d es: %llu\n", numero, factorial(numero));
    }

    return 0;
}
