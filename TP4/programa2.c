//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>

// Función que determina si un número es par o impar
int esParOImpar(int num) {
    if (num % 2 == 0) {
        return 1; // Retorna 1 si el número es par
    } else {
        return 2; // Retorna 2 si el número es impar
    }
}

int main() {
    int numero;
    int resultado;

    // Pedir al usuario que ingrese un número entero
    printf("Introduce un número entero: ");
    scanf("%d", &numero);

    // Llamar a la función para determinar si es par o impar
    resultado = esParOImpar(numero);

    // Imprimir el mensaje correspondiente
    if (resultado == 1) {
        printf("El número %d es par.\n", numero);
    } else {
        printf("El número %d es impar.\n", numero);
    }

    return 0;
}
