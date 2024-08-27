//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

int main() {
    int N, i, numero;
    int maximo, minimo;
    float suma = 0, media;

    printf("Introduce el numero de elementos (N): ");
    scanf("%d", &N);

    // Verificar que N sea positivo
    if (N <= 0) {
        printf("El numero de elementos debe ser mayor que 0.\n");
        return 1;
    }

    // Leer los números y calcular el máximo, mínimo y la suma
    printf("Introduce %d numeros:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &numero);

        if (i == 0) {
            maximo = minimo = numero; // Inicializar maximo y minimo con el primer número
        } else {
            if (numero > maximo) {
                maximo = numero;
            }
            if (numero < minimo) {
                minimo = numero;
            }
        }

        suma += numero;
    }

    media = suma / N;

    // Mostrar los resultados
    printf("El numero mas grande es: %d\n", maximo);
    printf("El numero mas pequeño es: %d\n", minimo);
    printf("La media es: %.2f\n", media);

    return 0;
}
