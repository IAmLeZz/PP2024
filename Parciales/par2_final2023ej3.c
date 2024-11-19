//
// Created by Álvaro on 11/19/2024.
//
#include <stdio.h>

int nCifra(int num, int k) {
    if (k==1) {
        return num%10;
    }
    return nCifra(num/10, k-1);
}

int main() {
    int ncifra = nCifra(5214682, 3);
    printf("%d", ncifra);
}