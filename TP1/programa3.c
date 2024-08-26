//
// Created by Álvaro on 8/26/2024.
//
#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operacion;

    // Leer los números
    printf("Ingrese el primer número: ");
    scanf("%f", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);

    // Leer el operador
    printf("Ingrese la operación (+, -, *, /): ");
    scanf(" %c", &operacion);

    // Realizar la operación correspondiente
    switch (operacion) {
        case '+':
            resultado = num1 + num2;
        printf("Resultado: %.2f\n", resultado);
        break;
        case '-':
            resultado = num1 - num2;
        printf("Resultado: %.2f\n", resultado);
        break;
        case '*':
            resultado = num1 * num2;
        printf("Resultado: %.2f\n", resultado);
        break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2f\n", resultado);
            } else {
                printf("Error: División por cero no permitida.\n");
            }
        break;
        default:
            printf("Operación no válida.\n");
        break;
    }

    return 0;
}