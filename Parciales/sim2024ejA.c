//
// Created by Álvaro on 9/28/2024.
//
#include <stdio.h>
void ord_inser(int v[], int ce){
  int i, j, clave;
  for (i = 0; i < ce; i++) {
    clave = v[i];
    j = i -1;

    while(j >= 0 && v[j] > clave) {
      v[j+1] = v[j];
      j = j-1;
    }
    v[j+1] = clave;
  }

}

void imprimirArreglo(int v[], int ce) {
  for (int i = 0; i < ce; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main() {
  int vector[] = {1, 59, 64, 66, 18};
  int n = sizeof(vector) / sizeof(vector[0]);

  printf("Arreglo original: \n");
  imprimirArreglo(vector, n);

  ord_inser(vector, n);
  printf("Arreglo ordenado: \n");
  imprimirArreglo(vector, n);

}
