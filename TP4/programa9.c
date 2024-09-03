//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>
#define TASA_CAMBIO 1300

void convertirMoneda(float monto, char tipo) {
    float resultado;

    if (tipo == 'P' || tipo == 'p') {
        // Convertir de pesos a dólares
        resultado = monto / TASA_CAMBIO;
        printf("%.2f ARS son %.2f USD\n", monto, resultado);
    } else if (tipo == 'D' || tipo == 'd') {
        // Convertir de dólares a pesos
        resultado = monto * TASA_CAMBIO;
        printf("%.2f USD son %.2f ARS\n", monto, resultado);
    } else {
        printf("Tipo de conversiOn no valido. Use 'P' para pesos a dolares o 'D' para dolares a pesos.\n");
    }
}

int main() {
    float monto;
    char tipo;

    printf("Ingrese el monto a convertir: ");
    scanf("%f", &monto);
    printf("Ingrese el tipo de conversion ('P' para pesos a dolares, 'D' para dolares a pesos): ");
    scanf(" %c", &tipo);

    convertirMoneda(monto, tipo);

    return 0;
}
