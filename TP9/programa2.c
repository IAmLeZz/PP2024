//
// Created by Álvaro on 11/3/2024.
//
#include <stdio.h>
#define TAM 200

char devolverCaracter(char texto[TAM], int k, int cant) {
    char caracter;
    if (cant == k) {
        caracter = texto[cant];
    } else {
        if (k > cant) {
            caracter = 'N';
        } else {
            caracter = devolverCaracter(texto, k , cant-1);
        }
    }
    return caracter;
}

// Funcion del ej anterior
int devolverCantCaracteres(char texto[TAM], int e) {
    int cont = 0;
    if (texto[e]!='\0'&&e<TAM) {
        e++;
        cont++;
        cont = cont + devolverCantCaracteres(texto, e);
    }
    return cont;

}

int main() {
    char texto[TAM], letra;
    int cant = 0, e = 0, k;

    printf("Ingrese el texto. Max 200 caracteres \n");
    gets(texto);
    printf("Ingresó %s \n", texto);
    cant = devolverCantCaracteres(texto, e);
    printf("El texto tiene %d caracteres \n", cant);

    printf("Que letra desea buscar? Ingrese el numero (primera letra siempre es 0) \n");
    scanf("%d", &k);
    letra = devolverCaracter(texto, k, cant);
    printf("La letra es %c \n", letra);
}