//
// Created by Álvaro on 9/10/2024.
//
#include <stdio.h>

int contarDigitos(int numero) {
    int contador = 0;
    if (numero == 0) {
        return 1;  // Para manejar el caso donde el número es 0
    }
    while (numero != 0) {
        numero /= 10;
        contador++;
    }
    return contador;
}

// Función para descomponer el número y almacenar los dígitos en un vector
void descomponerNumero(int numero, int vector[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        vector[i] = numero % 10;  // Obtener el último dígito
        numero /= 10;             // Eliminar el último dígito
    }
}

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
    int numero;

    printf("Introduce un número entero: ");
    scanf("%d", &numero);

    // Asegurarse de que el número sea positivo para evitar problemas de signo
    if (numero < 0) {
        printf("Por favor, introduce un número entero positivo.\n");
        return 1;
    }

    int n = contarDigitos(numero);

    // Declarar un vector para almacenar los dígitos
    int vector[n];

    // Descomponer el número en sus dígitos y almacenarlos en el vector
    descomponerNumero(numero, vector, n);

    // Imprimir el vector
    imprimirVector(vector, n);

    return 0;
}
