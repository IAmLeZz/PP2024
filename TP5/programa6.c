//
// Created by Álvaro on 9/9/2024.
//
#include <stdio.h>

void leerVector(int A[], int n){
  for (int i = 0; i < n; i++){
    printf("Introduce el valor para A[%d]:", i+1);
    scanf("%d", &A[i]);
  }


}

void imprimirVector(int A[], int n, const char* mensaje){
  printf("%s\n", mensaje);
  for (int i = 0; i < n; i++){
    printf("arr[%d] = %d\n", i+1, A[i]);
  }
}

void sumarTerminos(int original[], int auxiliar[], int n) {
    int mitad = n / 2;  // Para recorrer la mitad del vector

    for (int i = 0; i < mitad; i++) {
        auxiliar[i] = original[i] + original[n - i - 1];
    }

    // Si n es impar, agregar el término del medio sin cambios
    if (n % 2 != 0) {
        auxiliar[mitad] = original[mitad];  // El término del medio se carga tal cual
    }


}

int main(){
  int n;

    // Solicitar el tamaño del vector
    printf("Introduce el número de elementos del vector (par o impar): ");
    scanf("%d", &n);

    // Declarar el vector de tamaño n
    int original[n];
    int auxiliar[(n + 1) / 2];  // El tamaño del vector auxiliar es la mitad de n (redondeado hacia arriba)

    // Leer los valores del vector original
    leerVector(original, n);

    // Realizar las sumas y cargar el vector auxiliar
    sumarTerminos(original, auxiliar, n);

    // Imprimir el vector original
    imprimirVector(original, n, "Vector original:");

    // Imprimir el vector auxiliar
    imprimirVector(auxiliar, (n + 1) / 2, "Vector auxiliar:");

    return 0;
}