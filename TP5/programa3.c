//
// Created by Álvaro on 9/9/2024.
//
#include <stdio.h>

void leerVector(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Introduce el valor para A[%d]: ", i+1);
        scanf("%d", &A[i]);
    }
}

void imprimirVector(int A[], int n, const char* mensaje) {
    printf("%s\n", mensaje);
    for (int i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i+1, A[i]);
    }
}

void intercambiarElementos(int A[], int n) {
    int temp; // Variable temporal para el intercambio
    for (int i = 0; i < n / 2; i++) {
        temp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = temp;
    }
}

int main() {
    int n;

    printf("Introduce el número de elementos del vector: ");
    scanf("%d", &n);

    int A[n];

    leerVector(A, n);

    imprimirVector(A, n, "Vector original:");

    intercambiarElementos(A, n);

    imprimirVector(A, n, "Vector intercambiado:");

    return 0;
}
