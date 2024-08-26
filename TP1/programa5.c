//
// Created by Álvaro on 8/26/2024.
//
#include <stdio.h>

int main() {
    double num1, num2, num3;

    // Leer los tres números
    printf("Ingrese el primer número: ");
    scanf("%lf", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%lf", &num2);
    printf("Ingrese el tercer número: ");
    scanf("%lf", &num3);

    // Ordenar los números en forma ascendente
    double temp;

    // Comparar y ordenar
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num1 > num3) {
        temp = num1;
        num1 = num3;
        num3 = temp;
    }

    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }

    // Imprimir los números en orden ascendente
    printf("Los números en orden ascendente son: %.2lf, %.2lf, %.2lf\n", num1, num2, num3);

    return 0;
}