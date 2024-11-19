//
// Created by Álvaro on 11/6/2024.
//
#include <stdio.h>

int pow(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * pow(base, exp-1);
}

int main() {
    int base = 2, exp = 5;
    int power = pow(base, exp);
    printf("%d", power);
}