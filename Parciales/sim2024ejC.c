//
// Created by Álvaro on 9/28/2024.
//
#include <stdio.h>
#define FILAS 12
#define COLUMNAS 31

float calcularTemperaturaMediaMes(int mes, float temperaturaMaxima[FILAS][COLUMNAS]) {
    int diasEnMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    float suma = 0;
    for (int i = 0; i < diasEnMes[mes-1]; i++) {
        suma += temperaturaMaxima[mes-1][i];
    }
    return suma / diasEnMes[mes-1];

}

void cargarTemperaturas(float temperaturaMaxima[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        printf("Mes %d: \n", i+1);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Ingrese la temperatura máxima del día [%d]: ", j+1);
            scanf("%f", &temperaturaMaxima[i][j]);
        }
    }
}

void imprimirTemperaturaMaximaDelAño(float temperaturaMaxima[FILAS][COLUMNAS], int *mesMax, int *diaMax, float *maxTemp) {
    *maxTemp = temperaturaMaxima[0][0];
    *mesMax = 1;
    *diaMax = 1;
    int diasEnMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i = 0; i < FILAS; i++) {
        for (int j = 0; j < diasEnMes[i]; j++) {
            if (temperaturaMaxima[i][j] > *maxTemp) {
                *maxTemp = temperaturaMaxima[i][j];
                *mesMax = i+1;
                *diaMax = j+1;
            }
        }
    }

}

int main() {
    float temperaturaMaxima[FILAS][COLUMNAS];
    int mes, mesMax, diaMax;
    float maxTemp;

    cargarTemperaturas(temperaturaMaxima);
    printf("Ingrese el mes para calcular la temperatura maxima media \n");
    scanf("%d", &mes);
    float temperaturaMediaMes = calcularTemperaturaMediaMes(mes, temperaturaMaxima);
    printf("La temperatura promedio del mes %d es: %.2f", mes, temperaturaMediaMes);
    imprimirTemperaturaMaximaDelAño(temperaturaMaxima, &mesMax, &diaMax, &maxTemp);
    printf("La temperatura máxima del año fue %.2f y ocurrió el día %d del mes %d\n", maxTemp, diaMax, mesMax);

}