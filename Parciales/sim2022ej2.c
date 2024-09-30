//
// Created by Álvaro on 9/30/2024.
//
#include <stdio.h>
#define MAX 10

int cargarAprobados(int alumnos[MAX], int notas[MAX], int aprobados[MAX], int ce) {
    int j = 0;
    for (int i = 0; i < ce; i++) {
        if (notas[i] >= 4) {
            aprobados[j] = alumnos[i];
            j++;
        }
    }
    return j;
}

int main() {
    int alumnos[7] = {101, 102, 103, 104, 105, 106, 107};
    int notas[7] = {6, 3, 4, 2, 9,5,10};
    int aprobados[MAX];
    int ce = 7;

    int cantidadAprobados = cargarAprobados(alumnos, notas, aprobados, ce);
    printf("Los alumnos aprobados son: \n");
    for(int i = 0; i < cantidadAprobados; i++) {
       printf("%d ", aprobados[i]);
    }


}