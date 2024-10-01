//
// Created by Álvaro on 9/30/2024.
//
#include <stdio.h>
void inser(int v[], int ce) {
    int i, j, temp;
    for (i = 1; i < ce; i++) {
        temp = v[i];

        j = i-1;
        printf("%d, %d \n", v[j], v[i]);
        while (j >= 0 && v[j]>temp) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
        printf("Iteracion %d: ", i+1);
           for(int k = 0; k < ce; k++) {
               printf("%d ", v[k]);
           }
    }
}

int main() {
    int vector[5] = {1, 59, 64 , 66, 18};
    int ce = 5;
    inser(vector, ce);
    for(int i = 0; i < ce; i++) {
        printf("%d ", vector[i]);
    }
}