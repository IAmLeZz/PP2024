//
// Created by Álvaro on 8/26/2024.
//

#include <stdio.h>

int main() {
    int d1, d2, d3, d4;

    // Leer los 4 dígitos
    printf("Ingrese el primer dígito: ");
    scanf("%d", &d1);
    printf("Ingrese el segundo dígito: ");
    scanf("%d", &d2);
    printf("Ingrese el tercer dígito: ");
    scanf("%d", &d3);
    printf("Ingrese el cuarto dígito: ");
    scanf("%d", &d4);

    // Formar el número entero
    int entero = d1 * 1000 + d2 * 100 + d3 * 10 + d4;

    // Imprimir el número entero formado
    printf("El número entero formado es: %d\n", entero);

    return 0;
}
