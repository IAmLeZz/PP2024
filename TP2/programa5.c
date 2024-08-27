//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    float temp, converted_temp;
    char scale;

    printf("Ingrese la temperatura: ");
    scanf("%f", &temp);

    printf("Ingrese la escala (C para Celsius, F para Fahrenheit): ");
    scanf(" %c", &scale);

    // Convertir la temperatura según la escala ingresada
    if (scale == 'C' || scale == 'c') {
        // Convertir de Celsius a Fahrenheit
        converted_temp = 32.0 + 1.8 * temp;
        printf("%.2f grados Celsius es igual a %.2f grados Fahrenheit.\n", temp, converted_temp);
    } else if (scale == 'F' || scale == 'f') {
        // Convertir de Fahrenheit a Celsius
        converted_temp = (temp - 32.0) * 5.0 / 9.0;
        printf("%.2f grados Fahrenheit es igual a %.2f grados Celsius.\n", temp, converted_temp);
    } else {
        printf("Escala no válida. Use 'C' para Celsius o 'F' para Fahrenheit.\n");
    }

    return 0;
}