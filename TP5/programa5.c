//
// Created by Álvaro on 9/9/2024.
//
#include <stdio.h>

void leerArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Introduce el valor para arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

// Función para buscar un elemento en el arreglo (caso no repetido)
int buscarElemento(int arr[], int n, int elemento) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == elemento) {
            return i;  // Retorna la posición donde se encontró
        }
    }
    return -1;  // Si no se encuentra, retorna -1
}

// Función para buscar y contar un elemento en el arreglo (caso con repetición)
int buscarYContarElemento(int arr[], int n, int elemento, int posiciones[]) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == elemento) {
            posiciones[contador] = i;  // Guarda la posición en el arreglo
            contador++;
        }
    }
    return contador;
}

int main() {
    int n, elemento;

    printf("Introduce el número de elementos del arreglo: ");
    scanf("%d", &n);

    int arr[n];

    leerArreglo(arr, n);

    printf("Introduce el elemento a buscar: ");
    scanf("%d", &elemento);

    // CASO A: El elemento no se repite (se busca una única vez)
    printf("\n---- Caso A: Buscar un único elemento ----\n");
    int posicion = buscarElemento(arr, n, elemento);

    if (posicion != -1) {
        printf("El elemento %d se encontró en la posición: %d\n", elemento, posicion + 1);
    } else {
        printf("El elemento %d no se encontró en el arreglo.\n", elemento);
    }

    // CASO B: El elemento puede repetirse o no estar
    printf("\n---- Caso B: Buscar elemento con posibles repeticiones ----\n");
    int posiciones[n];  // Arreglo para almacenar las posiciones donde se encuentra el elemento
    int cantidad = buscarYContarElemento(arr, n, elemento, posiciones);

    if (cantidad > 0) {
        printf("El elemento %d se encontró %d veces en las posiciones: ", elemento, cantidad);
        for (int i = 0; i < cantidad; i++) {
            printf("%d ", posiciones[i] + 1);
        }
        printf("\n");
    } else {
        printf("El elemento %d no se encontró en el arreglo.\n", elemento);
    }

    return 0;
}
