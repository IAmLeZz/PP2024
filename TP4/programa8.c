//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>

// Función que realiza la operación basada en el operador dado
float calcular(float num1, float num2, char operador) {
    float resultado;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
        break;
        case '-':
            resultado = num1 - num2;
        break;
        case '*':
            resultado = num1 * num2;
        break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Error: División por cero.\n");
                return 0;
            }
        break;
        default:
            printf("Error: Operador no válido.\n");
        return 0;
    }

    return resultado;
}

int main() {
    float num1, num2, resultado;
    char operador;

    // Solicitar al usuario que ingrese los dos números y el operador
    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);
    printf("Ingrese el operador (+, -, *, /): ");
    scanf(" %c", &operador);

    resultado = calcular(num1, num2, operador);

    // Imprimir el resultado
    if (operador == '+' || operador == '-' || operador == '*' || (operador == '/' && num2 != 0)) {
        printf("Resultado: %.2f\n", resultado);
    }

    return 0;
}
