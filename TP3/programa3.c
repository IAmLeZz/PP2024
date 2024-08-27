//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int i;

    printf("Nro\tNro^2\tNro^3\n");

    for (i = 1; i <= 100; i++) {
        printf("%d\t%d\t%d\n", i, i * i, i * i * i);
    }

    return 0;
}
