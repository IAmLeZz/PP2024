//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double toRadians(int grados, int minutos, int segundos) {
    double radianes;
    radianes = grados * PI / 180.0;
    radianes += minutos * PI / 10800.0;
    radianes += segundos * PI / 648000.0;
    return radianes;
}

int main() {
    int grados, minutos, segundos;
    double radianes;

    // Leer valores
    printf("Ingrese grados: ");
    scanf("%d", &grados);
    printf("Ingrese minutos: ");
    scanf("%d", &minutos);
    printf("Ingrese segundos: ");
    scanf("%d", &segundos);

    // Convertir a radianes
    radianes = toRadians(grados, minutos, segundos);

    // Imprimir el resultado
    printf("El angulo en radianes es: %.10f\n", radianes);

    return 0;
}
