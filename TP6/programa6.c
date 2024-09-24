//
// Created by Álvaro on 9/24/2024.
//
#include <stdio.h>

void fibonacci(double fibo[]) {
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < 100; i++) {
        fibo[i] = fibo[i-1]+ fibo[i-2];
    }
}

void mostrar(double fibo[]) {
    for(int i = 0; i<100; i++) {
        printf("\nPosición[%d]: %f", i, fibo[i]);
    }
}
double buscarFibo(double fibo[], int posicion) {
    int inicio = 0;
    int fin = 100 - 1;

    // Búsqueda binaria en el rango [0, MAX-1]
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (medio == posicion) {
            return fibo[medio]; // Se encontró la posición
        }
        else if (medio < posicion) {
            inicio = medio + 1; // Buscar en la mitad derecha
        }
        else {
            fin = medio - 1;    // Buscar en la mitad izquierda
        }
    }

    return -1;  // Si la posición no se encuentra
}

int main(){
    double FIB[100];
    int pos = 0;
    fibonacci(FIB);
    mostrar(FIB);
    printf("Cual es la posición a buscar?: ");
    scanf("%d", &pos);
    if (pos >= 0 && pos < 100) {
        double res = buscarFibo(FIB, pos);
        if (res != -1) {
            printf("El elemento en la posición %d es: %f\n", pos, res);
        } else {
            printf("No se encontró la posición en el vector. \n");
        }
    }
    else {
        printf("Posición fuera de rango. \n");
    }
    return 0;


}