//
// Created by Álvaro on 12/16/2024.
//
#include <stdio.h>

int c_o(char *str, char car) {
    int n;
    n = 0;

    if (*str!='\0') {
        if (*str == car) {
            n = 1;
        }
        n = n+c_o(++str, car);
    }
    return n;
}

int main() {
    int num = c_o("Hola", 'x');

printf("%d", num);
}
