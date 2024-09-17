//
// Created by Álvaro on 9/13/2024.
//
#include <stdio.h>
#include <string.h>

void concatenarNumeros(int numeros[], int n, int resultado[], int *m) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int num = numeros[i];
        char str[10];
        sprintf(str, "%d", num);
        for (int j = 0; j < strlen(str); j++) {
            resultado[k++] = str[j] - '0';
        }
        resultado[k++] = -1;
    }
    *m = k;
}

int main() {
    int n;
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &n);

    int numeros[n];
    printf("Ingrese los números:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    int resultado[100];
    int m;

    concatenarNumeros(numeros, n, resultado, &m);

    printf("El vector resultante es:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
