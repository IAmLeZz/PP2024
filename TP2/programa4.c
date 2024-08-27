//
// Created by Álvaro on 8/26/2024.
//
#include <stdio.h>

#define PI 3.14159265

int main() {
    float diametro, volumen, area;

    printf("Ingrese el diametro de la esfera: ");
    scanf("%f", &diametro);

    if (diametro <= 0) {
        printf("Error: El diametro debe ser un numero positivo.\n");
    } else {
        // Calcular el volumen y el área
        volumen = PI * (diametro * diametro * diametro) / 6;
        area = PI * (diametro * diametro) / 4;

        printf("Volumen de la esfera: %.2f\n", volumen);
        printf("Area del circulo mayor: %.2f\n", area);
    }

    return 0;
}