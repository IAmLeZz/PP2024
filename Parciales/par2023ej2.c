#include <stdio.h>
//
// Created by Álvaro on 10/1/2024.
//
void eliminarRepetidos(int v[], int ce){
        for(int i = 0; i < ce; i++) {
        if(v[i] == 0) {
            continue;
        }

        for(int j = i+1; j < ce; j++) {
            if (v[i] == v[j]) {
                v[j] = 0;
            }
        }
    }
}

int main() {
    int vector[6] = {34, 20, 34, 14, 9, 14};
    int ce = 6;
    eliminarRepetidos(vector, ce);
    for(int i = 0; i < ce; i++) {
        printf("%d ", vector[i]);
    }

}