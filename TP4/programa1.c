//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>

// Función que calcula el MCD de dos números usando el algoritmo de Euclides
int calcularMCD(int a, int b) {
    int r;

    // Mientras el resto no sea 0
    while (b != 0) {
        r = a % b; // Calcula el resto de la división de a entre b
        a = b;     // El nuevo valor de a será el valor de b
        b = r;     // El nuevo valor de b será el resto
    }

    return a; // Cuando el resto es 0, a es el MCD
}

int main() {
    int num1, num2, mcd;

    // Pedir al usuario que ingrese dos números
    printf("Introduce el primer numero: ");
    scanf("%d", &num1);
    printf("Introduce el segundo numero: ");
    scanf("%d", &num2);

    // Llamar a la función calcularMCD para encontrar el MCD de num1 y num2
    mcd = calcularMCD(num1, num2);

    // Mostrar el resultado
    printf("El MCD de %d y %d es: %d\n", num1, num2, mcd);

    return 0;
}