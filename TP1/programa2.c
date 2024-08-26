//
// Created by Álvaro on 8/26/2024.
//
#include <stdio.h>

int main() {
    float num1, num2;
    float suma, resta, producto, division;

    // Solicitar los números al usuario
    printf("Ingrese el primer número decimal: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo número decimal: ");
    scanf("%f", &num2);

    // Realizar las operaciones
    suma = num1 + num2;
    resta = num1 - num2;
    producto = num1 * num2;
    division = num1 / num2;

    // Mostrar los resultados
    printf("Suma - %.2f + %.2f = %.2f\n", num1, num2, suma);
    printf("Resta - %.2f - %.2f = %.2f\n", num1, num2, resta);
    printf("Producto - %.2f * %.2f = %.2f\n", num1, num2, producto);
    printf("División - %.2f / %.2f = %.2f\n", num1, num2, division);

    return 0;
}