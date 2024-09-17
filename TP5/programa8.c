//
// Created by Álvaro on 9/13/2024.
//
#include <stdio.h>

// Función para calcular el número a partir de los dígitos almacenados en el vector
int calcularNumero(int vector[], int n) {
    int numero = 0;
    for (int i = 0; i < n; i++) {
        numero = numero * 10 + vector[i];  // Desplazar el número y sumar el dígito actual
    }
    return numero;
}

// Función para imprimir el vector
void imprimirVector(int vector[], int n) {
    printf("Vector A = (");
    for (int i = 0; i < n; i++) {
        printf("%d", vector[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(")\n");
}

int main() {
    int n;

    // Solicitar el número de dígitos del vector
    printf("Introduce el número de dígitos: ");
    scanf("%d", &n);

    // Declarar el vector de tamaño n
    int A[n];

    // Leer los dígitos del número
    printf("Introduce los dígitos del número:\n");
    for (int i = 0; i < n; i++) {
        printf("A[%d]: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Imprimir el vector
    imprimirVector(A, n);

    // Calcular el número a partir de los dígitos
    int numero = calcularNumero(A, n);

    // Mostrar el número reconstruido
    printf("El número reconstruido es: %d\n", numero);

    return 0;
}
