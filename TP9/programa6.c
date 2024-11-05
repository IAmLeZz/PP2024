//
// Created by Álvaro on 11/4/2024.
//
#include <stdio.h>

// version iterativa
int sumNaturales(int n) {
    int rta = 0;
    int temp = n;
    for(int i = 0; i <= temp; i++) {
        rta = rta + n;
        n--;
    }
    return rta;
}

int main() {
    int num = sumNaturales(6);
    printf("%d", num);
}