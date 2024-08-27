//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    double operando1, operando2, resultado;
    char operador;

    // Leer los operandos y el operador
    printf("Introduce el primer operando: ");
    scanf("%lf", &operando1);
    printf("Introduce el segundo operando: ");
    scanf("%lf", &operando2);
    printf("Introduce el operador (+, -, *, /): ");
    scanf(" %c", &operador);

    // Evaluar la operación correspondiente
    switch (operador) {
        case '+':
            resultado = operando1 + operando2;
        printf("Resultado: %.2lf\n", resultado);
        break;
        case '-':
            resultado = operando1 - operando2;
        printf("Resultado: %.2lf\n", resultado);
        break;
        case '*':
            resultado = operando1 * operando2;
        printf("Resultado: %.2lf\n", resultado);
        break;
        case '/':
            if (operando2 != 0) {
                resultado = operando1 / operando2;
                printf("Resultado: %.2lf\n", resultado);
            } else {
                printf("Error: División por cero no permitida.\n");
            }
        break;
        default:
            printf("Operador no válido.\n");
        break;
    }

    return 0;
}
