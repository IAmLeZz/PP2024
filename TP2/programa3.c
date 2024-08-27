//
// Created by Álvaro on 8/26/2024.
//
#include <stdio.h>

int main() {
    int x, y, z;

    printf("Ingrese tres números enteros: ");
    scanf("%d %d %d", &x, &y, &z);

    // Imprimir la cabecera de la tabla
    printf("Nro\tNro^2\tNro^3\tNro^4\n");

    // Imprimir la primera fila
    printf("%d\t%d\t%d\t%d\n", x, x*x, x*x*x, x*x*x*x);

    // Imprimir la segunda fila
    printf("%d\t%d\t%d\t%d\n", y, y*y, y*y*y, y*y*y*y);

    // Imprimir la tercera fila
    printf("%d\t%d\t%d\t%d\n", z, z*z, z*z*z, z*z*z*z);

    return 0;
}
