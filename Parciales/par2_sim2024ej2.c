//
// Created by Álvaro on 11/13/2024.
//

#include <stdio.h>

int temperaturaPromedioSemana(int temperaturas[4][7], int semana) {
    int promedio = 0;
        for(int j = 0; j < 7; j++) {
            promedio += temperaturas[semana][j];
        }
    return promedio/7;

}

int temperaturaPromedioMes(int temperaturas[4][7]) {
    int suma = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            suma+=temperaturas[i][j];
        }
    }
    return suma/28;
}

void temperaturasMasAltasYBajas(int temperaturas[4][7]) {
    int tempBaja = temperaturas[1][1];
    int tempMasAlta = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            if (tempMasAlta < temperaturas[i][j]) {
                tempMasAlta = temperaturas[i][j];
            }
            if (tempBaja > temperaturas[i][j]) {
                tempBaja = temperaturas[i][j];
            }
        }
    }
    printf("La temperatura mas alta es %d y la mas baja es %d \n", tempMasAlta, tempBaja);
}

int main() {
    int temperaturas[4][7] = {
        {20, 22, 19, 21, 18, 20, 22},
        {23, 21, 20, 22, 24, 25, 26},
        {27, 26, 29, 26, 23, 21, 20},
        {19, 18, 20, 21, 22, 23, 24}
    };

    int semana = 2; // Ejemplo: promedio de la tercera semana
    int promedio = temperaturaPromedioSemana(temperaturas, semana);
    int promedioMes = temperaturaPromedioMes(temperaturas);

    if (promedio != -1) {
        printf("La temperatura promedio de la semana %d es: %d\n y la del mes es %d", semana + 1, promedio, promedioMes);
    }
    temperaturasMasAltasYBajas(temperaturas);
    return 0;
}