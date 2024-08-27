//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int dig1, dig2, tope, siguiente;

    // Leer los dos dígitos y el tope
    printf("Introduce el primer digito: ");
    scanf("%d", &dig1);
    printf("Introduce el segundo digito: ");
    scanf("%d", &dig2);
    printf("Introduce el tope: ");
    scanf("%d", &tope);

    // Imprimir los dos primeros dígitos
    printf("La serie es: %d, %d", dig1, dig2);

    // Generar la serie
    siguiente = dig2 + (dig2 - dig1);
    while (siguiente <= tope) {
        printf(", %d", siguiente);
        dig1 = dig2;
        dig2 = siguiente;
        siguiente = dig2 + (dig2 - dig1);
    }

    printf("\n");

    return 0;
}
