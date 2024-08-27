//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>
#include <stdlib.h>

void imprimirMayor(int a, int b, int c) {
    int mayor = a;
    if (b > mayor) mayor = b;
    if (c > mayor) mayor = c;
    printf("El mayor entero leído es: %d\n", mayor);
}

void imprimirMenorAbsoluto(int a, int b, int c) {
    int menor = abs(a);
    if (abs(b) < menor) menor = abs(b);
    if (abs(c) < menor) menor = abs(c);
    printf("El menor en valor absoluto es: %d\n", menor);
}

void imprimirOrdenAscendente(int a, int b, int c) {
    int temp;
    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    printf("Los tres valores en orden ascendente son: %d, %d, %d\n", a, b, c);
}

void imprimirOrdenInverso(int a, int b, int c) {
    printf("Los tres valores en orden inverso al leído son: %d, %d, %d\n", c, b, a);
}

int main() {
    int a, b, c, opcion;

    printf("Introduce tres enteros positivos: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Elige una opción de impresión:\n");
    printf("1. El mayor entero leído\n");
    printf("2. El menor en valor absoluto\n");
    printf("3. Los tres valores en orden ascendente\n");
    printf("4. Los tres valores en orden inverso al leído\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            imprimirMayor(a, b, c);
        break;
        case 2:
            imprimirMenorAbsoluto(a, b, c);
        break;
        case 3:
            imprimirOrdenAscendente(a, b, c);
        break;
        case 4:
            imprimirOrdenInverso(a, b, c);
        break;
        default:
            printf("Opción no válida\n");
        break;
    }

    return 0;
}
