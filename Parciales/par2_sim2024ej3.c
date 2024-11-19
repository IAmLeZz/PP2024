//
// Created by Álvaro on 11/13/2024.
//
#include <stdio.h>
#define MAX 100

char *b1(char *s, char c) {
    char *rta;
    if (*s==c) {
        rta = s;
    }
    else {
        if(*s=='\0') {
            rta = NULL;
        } else {
            rta = b1(++s, c);
        }
    }
    return rta;
}

int main() {
    char *texto = "pepa";
    char *b2 = b1(texto, 'a');
    printf("%p", b2);
}