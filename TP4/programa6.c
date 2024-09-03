//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>

// Constante de conversión
#define KM_TO_MILES 0.621371
#define MILES_TO_KM 1.60934

// Función que convierte kilómetros a millas
double convertirKmAMillas(double km) {
    return km * KM_TO_MILES;
}

// Función que convierte millas a kilómetros
double convertirMillasAKm(double millas) {
    return millas * MILES_TO_KM;
}

int main() {
    double cantidad, resultado;
    char tipoConversion;

    printf("Ingrese la cantidad a convertir: ");
    scanf("%lf", &cantidad);

    printf("Ingrese el tipo de conversion (K para Km a millas, M para millas a Km): ");
    scanf(" %c", &tipoConversion);

    // Realizar la conversión según la opción ingresada
    if (tipoConversion == 'K' || tipoConversion == 'k') {
        resultado = convertirKmAMillas(cantidad);
        printf("%.2f km son %.2f millas.\n", cantidad, resultado);
    } else if (tipoConversion == 'M' || tipoConversion == 'm') {
        resultado = convertirMillasAKm(cantidad);
        printf("%.2f millas son %.2f km.\n", cantidad, resultado);
    } else {
        printf("Opción de conversión no válida.\n");
    }

    return 0;
}