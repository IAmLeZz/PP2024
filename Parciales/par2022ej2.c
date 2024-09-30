//
// Created by Álvaro on 9/29/2024.
//
#include <stdio.h>

void invertirCerosYUnos(int v[], int ce) {
    int i, j, aux;
    for (i = 0; i < ce; i++) {
        for (j = 0; j < ce-1; j++) {
            if (v[j] < v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }

        }
    }
}

int main(){
    int vector[9] = {1, 0, 1, 1, 0, 1, 0, 0, 1};
    int ce = 9;

    printf("Vector original \n");
    for(int i = 0; i < ce; i++) {
        printf("%d ", vector[i]);
    }
    printf("Ceros y unos invertidos: \n");
    invertirCerosYUnos(vector, ce);
    for(int k = 0; k < ce; k++) {
        printf("%d ", vector[k]);
    }

}