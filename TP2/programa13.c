//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    float altura;
    char contextura;

    // Leer la altura y la contextura física
    printf("Introduce la altura (en metros, por ejemplo, 1.70): ");
    scanf("%f", &altura);
    printf("Introduce la contextura fisica (c para chica, m para mediana, g para grande): ");
    scanf(" %c", &contextura);

    // Determinar el rango de peso ideal según la altura y la contextura física
    if (altura >= 1.55 && altura <= 1.65) {
        if (contextura == 'c') {
            printf("Peso ideal: 50.0 - 54.0 kg\n");
        } else if (contextura == 'm') {
            printf("Peso ideal: 53.0 - 58.0 kg\n");
        } else if (contextura == 'g') {
            printf("Peso ideal: 56.0 - 63.0 kg\n");
        } else {
            printf("Contextura física no válida.\n");
        }
    } else if (altura >= 1.66 && altura <= 1.75) {
        if (contextura == 'c') {
            printf("Peso ideal: 56.5 - 60.5 kg\n");
        } else if (contextura == 'm') {
            printf("Peso ideal: 59.0 - 65.0 kg\n");
        } else if (contextura == 'g') {
            printf("Peso ideal: 63.0 - 71.0 kg\n");
        } else {
            printf("Contextura física no válida.\n");
        }
    } else if (altura >= 1.76 && altura <= 1.85) {
        if (contextura == 'c') {
            printf("Peso ideal: 63.5 - 68.0 kg\n");
        } else if (contextura == 'm') {
            printf("Peso ideal: 65.7 - 73.0 kg\n");
        } else if (contextura == 'g') {
            printf("Peso ideal: 70.0 - 79.0 kg\n");
        } else {
            printf("Contextura física no válida.\n");
        }
    } else if (altura >= 1.86 && altura <= 2.00) {
        if (contextura == 'c') {
            printf("Peso ideal: 71.0 - 76.0 kg\n");
        } else if (contextura == 'm') {
            printf("Peso ideal: 74.0 - 82.0 kg\n");
        } else if (contextura == 'g') {
            printf("Peso ideal: 79.0 - 88.0 kg\n");
        } else {
            printf("Contextura física no válida.\n");
        }
    } else {
        printf("Altura fuera del rango permitido.\n");
    }

    return 0;
}
