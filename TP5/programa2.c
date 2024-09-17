//
// Created by Álvaro on 9/9/2024.
//
#include <stdio.h>

void leerVector(int A[], int n){
  for(int i = 0; i < n; i++){
    printf("Introduce el valor de A[%d]:", i+1);
    scanf("%d", &A[i]);
  }
}

void imprimirVector(int A[], int n, int *mayor, int *posicion){
  *mayor = A[0];
  *posicion = 1;

  for (int i = 1; i < n; i++) {
    if (A[i] > *mayor) {
      *mayor = A[i];
      *posicion = i + 1;
    }
  }

}

int main(){
  int n;

  printf("Introduce el número de elementos del vector: ");
  scanf("%d", &n);

  int A[n];

  leerVector(A, n);
  int mayor, posicion;

  imprimirVector(A, n, &mayor, &posicion);
  printf("El elemento de mayor valor es: %d y ocupa la posición: %d del vector.\n", mayor, posicion);
  return 0;

}