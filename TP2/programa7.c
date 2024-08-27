//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

typedef struct {
    float real;
    float imaginaria;
} Complejo;

Complejo sumar(Complejo a, Complejo b) {
    Complejo resultado;
    resultado.real = a.real + b.real;
    resultado.imaginaria = a.imaginaria + b.imaginaria;
    return resultado;
}

Complejo restar(Complejo a, Complejo b) {
    Complejo resultado;
    resultado.real = a.real - b.real;
    resultado.imaginaria = a.imaginaria - b.imaginaria;
    return resultado;
}

Complejo multiplicar(Complejo a, Complejo b) {
    Complejo resultado;
    resultado.real = a.real * b.real - a.imaginaria * b.imaginaria;
    resultado.imaginaria = a.real * b.imaginaria + a.imaginaria * b.real;
    return resultado;
}

Complejo dividir(Complejo a, Complejo b) {
    Complejo resultado;
    float denominador = b.real * b.real + b.imaginaria * b.imaginaria;
    resultado.real = (a.real * b.real + a.imaginaria * b.imaginaria) / denominador;
    resultado.imaginaria = (a.imaginaria * b.real - a.real * b.imaginaria) / denominador;
    return resultado;
}

void imprimir(Complejo c) {
    if (c.imaginaria >= 0)
        printf("Resultado: %.2f + %.2fi\n", c.real, c.imaginaria);
    else
        printf("Resultado: %.2f - %.2fi\n", c.real, -c.imaginaria);
}

int main() {
    Complejo a, b, resultado;
    char opcion;

    printf("Ingrese la parte real e imaginaria del primer numero complejo: ");
    scanf("%f %f", &a.real, &a.imaginaria);

    printf("Ingrese la parte real e imaginaria del segundo numero complejo: ");
    scanf("%f %f", &b.real, &b.imaginaria);

    printf("Seleccione la operacion (+, -, *, /): ");
    scanf(" %c", &opcion);

    switch (opcion) {
        case '+':
            resultado = sumar(a, b);
            break;
        case '-':
            resultado = restar(a, b);
            break;
        case '*':
            resultado = multiplicar(a, b);
            break;
        case '/':
            resultado = dividir(a, b);
            break;
        default:
            printf("Opcion no valida.\n");
            return 1;
    }

    imprimir(resultado);

    return 0;
}
