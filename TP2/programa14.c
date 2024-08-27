//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int year;

    // Leer el año
    printf("Introduce un año: ");
    scanf("%d", &year);

    // Determinar si es bisiesto
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("El año %d es bisiesto.\n", year);
    } else {
        printf("El año %d no es bisiesto.\n", year);
    }

    return 0;
}
