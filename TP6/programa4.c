//
// Created by Álvaro on 9/24/2024.
//
#include <stdio.h>

int buscarNota(int notas[], int libretas[], int n, int legajo) {
    int inicio = 0, fin = n-1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (libretas[medio] == legajo) {
            return notas[medio];
        } else if (libretas[medio] < legajo) {
            inicio = medio + 1;
        }
        else {
            fin = medio -1 ;
        }

    }
return -1;
}

int main() {
    int notas[] = {4, 4, 5,5};
    int libretas[] = {1001,1002,1003,1004};
    int n = 4;

    int legajo;

    printf("Ingrese el numero de legajo a buscar: ");
    scanf("%d", &legajo);
    int nota = buscarNota(notas, libretas, n, legajo);
    if (nota !=-1) {
        printf("La nota del alumno con legajo %d es: %d", legajo, nota);
    } else {
        printf("El legajo %d no se encuentra en el sistema. \n", legajo);
    }
    return 0;

}
