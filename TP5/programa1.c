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

void imprimirVector(int A[], int n){
  for(int i = 0; i < n; i++){
    printf("A[%d] = %d\n", i+1, A[i]);
  }
}

int main(){
  int n;

  printf("Introduce el número de elementos del vector: ");
  scanf("%d", &n);

  int A[n];

  leerVector(A, n);
  imprimirVector(A, n);

  return 0;

}