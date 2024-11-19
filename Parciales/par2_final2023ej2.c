//
// Created by Álvaro on 11/19/2024.
//
#include <stdio.h>
#define MAX 100

double *men(double *v, int n) {
    double *min = v;
    for(int i = 0; i < n; i++) {
        if (*(v+i)<(*min)) {
            min = (v+i);
        }
    }
    return min;
}