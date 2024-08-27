//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int dia, mes, year;
    int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Leer la fecha
    printf("Introduce una fecha (dd mm aaaa): ");
    scanf("%d %d %d", &dia, &mes, &year);

    // Verificar que la fecha esté en el rango permitido
    if (year < 1900 || year > 1999 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        printf("Fecha no válida.\n");
        return 1;
    }

    // Ajustar febrero para años bisiestos
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        diasEnMes[1] = 29;
    }

    // Incrementar el día
    dia++;

    // Verificar si se debe incrementar el mes
    if (dia > diasEnMes[mes - 1]) {
        dia = 1;
        mes++;
    }

    // Verificar si se debe incrementar el año
    if (mes > 12) {
        mes = 1;
        year++;
    }

    // Imprimir el resultado
    printf("El dia siguiente es: %02d/%02d/%04d\n", dia, mes, year);

    return 0;
}