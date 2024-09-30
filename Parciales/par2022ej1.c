//
// Created by Álvaro on 9/29/2024.
//
#include <stdio.h>

void burbuInv(int v[], int ce) {
    int i, j, aux;
    int ordenado;

    for (i = 0; i < ce - 1; i++) {
        ordenado = 1;
        for (j = ce - 1; j > i; j--) {
            if (v[j] < v[j-1]) {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;

                ordenado = 0;
            }
        }
        printf("Iteracion %d:", i+1);
        for(int k = 0; k < ce; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
        if (ordenado) {
            break;
        }

    }
}

int main() {
    int vector[5] = {4,59,44,25,17};
    int ce = 5;
    printf("Arreglo original \n");
    for(int i = 0; i < ce; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    burbuInv(vector, ce);
}