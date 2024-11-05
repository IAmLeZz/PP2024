//
// Created by Álvaro on 11/5/2024.
//
#include <stdio.h>
#include <string.h>

int cadena (char cad[],int pi,int pf) {
    int r;
    if (pi >= pf) {
        return (0);
    }
    else {
        if (cad[pi]==cad[pf]) {
            r=cadena(cad, pi+1, pf-1);
        }
        else {
            r=1;
        }
    }

    return (r);
}

int main() {
    char texto[] = "aua";
    int pi = 0;
    int pf = strlen(texto);

    int cadenaCaracteres = cadena("radar", 0, 4);
    printf("%d", cadenaCaracteres);
}