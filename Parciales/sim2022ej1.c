//
// Created by Álvaro on 9/30/2024.
//
#include <stdio.h>

void burbu(int v[], int ce) {
    int i, j, aux, ordenado;
    for(i = 0; i < ce; i++) {
        ordenado = 1;
        for(j = 0; j < ce-1; j++) {
            if (v[j] < v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                ordenado = 0;
            }
        }
        printf("Iteracion %d: ", i+1);
        for (int k = 0; k < ce; k++) {
            printf("%d ", v[k]);
        }
        if (ordenado) {
            break;
        }
    }
}

int main() {
    int vector[5] = {4,59,44,25,170};
    int ce = 5;
    for (int i = 0; i < ce; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    burbu(vector, ce);

}