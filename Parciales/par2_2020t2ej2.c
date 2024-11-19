//
// Created by Álvaro on 11/10/2024.
//
#include <stdio.h>
#define MAX 100

double *men(double *v, int n) {
    double *min = v;

    for (int i = 0; i < n; i++) {
        if (*(v+i)>*min) {
            min = v+i;
        }
    }
    return min;
}

int main() {
    double v[25] = {23, 12, 52, 22, 11, 9, 3, 24};
    double *direc = men(v, 8);
    printf("%p", direc);
}