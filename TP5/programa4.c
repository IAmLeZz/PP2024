//
// Created by Álvaro on 9/9/2024.
//
#include <stdio.h>

// Función para leer un vector de 'n' elementos
void leerVector(int vec[], int n, char nombre) {
    printf("Introduce los elementos del vector %c:\n", nombre);
    for (int i = 0; i < n; i++) {
        printf("%c[%d]: ", nombre, i+1);
        scanf("%d", &vec[i]);
    }
}

// Función para imprimir un vector
void imprimirVector(int vec[], int n, char nombre) {
    printf("Vector %c: ", nombre);
    for (int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Función para sumar dos vectores
void sumarVectores(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }
}

// Función para calcular el producto escalar de dos vectores
int productoEscalar(int A[], int B[], int n) {
    int producto = 0;
    for (int i = 0; i < n; i++) {
        producto += A[i] * B[i];
    }
    return producto;
}

int main() {
    int n;

    // Solicitar el tamaño de los vectores
    printf("Introduce el número de elementos de los vectores: ");
    scanf("%d", &n);

    // Declarar los vectores A, B y C para la suma
    int A[n], B[n], C[n];

    // Leer los vectores A y B
    leerVector(A, n, 'A');
    leerVector(B, n, 'B');

    // Sumar los vectores A y B
    sumarVectores(A, B, C, n);

    // Calcular el producto escalar
    int producto = productoEscalar(A, B, n);

    // Imprimir los resultados
    imprimirVector(A, n, 'A');
    imprimirVector(B, n, 'B');
    imprimirVector(C, n, 'C'); // C es la suma de A y B
    printf("El producto escalar de A y B es: %d\n", producto);

    return 0;
}
