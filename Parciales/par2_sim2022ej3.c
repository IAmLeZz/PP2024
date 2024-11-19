//
// Created by Álvaro on 11/14/2024.
//

#include <stdio.h>
#define MAX 100

int numMasSignificativo(int n) {
    if (n > 10) {
        return numMasSignificativo(n/10);
    }
    return n;

}

int main() {
    int numSig = numMasSignificativo(54942);
    printf("%d", numSig);
}