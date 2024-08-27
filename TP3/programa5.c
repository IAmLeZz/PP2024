//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

// Función para calcular el factorial de un número
// Se usa unsigned long long porque los números son demasiado grandes para usar int
unsigned long long factorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero;

    printf("Introduce números enteros (introduce -1 para terminar):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == -1) {
            break;
        }

        if (numero < 0) {
            printf("El factorial no esta definido para numeros negativos.\n");
        } else {
            printf("El factorial de %d es %llu\n", numero, factorial(numero));
        }
    }

    return 0;
}