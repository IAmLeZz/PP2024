//
// Created by Álvaro on 10/11/2024.
//
#include <stdio.h>

#define MAX 100
typedef struct {
    char apellido[21];
    char nombre[21];
    char direccion[11];
    char telefono[6];
    int cuenta;
} persona;

void leerPersonas(persona p[MAX], int ce) {
    for (int i = 0; i < ce; i++) {
        printf("Ingrese los datos de la persona %d:\n", i+1);
        printf("Nombre (max 20 caracteres) \n");
        gets(p[i].nombre);
        printf("Apellido (max 20 caracteres) \n");
        gets(p[i].apellido);
        printf("Direccion (max 10 caracteres) \n");
        gets(p[i].direccion);
        printf("Telefono (max 6 caracteres) \n");
        gets(p[i].telefono);
        printf("Num de cuenta (max 4 digitos) \n");
        scanf("%d", &p[i].cuenta);
        getchar();
        printf("\n");
    }
}

void ordenarPersonas(persona p[MAX], int ce) {
    int i, j;
    persona temp;
    for(i = 1; i < ce; i++) {
        temp = p[i];
        j = i-1;
        while (j >= 0 && p[j].cuenta > temp.cuenta) {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
}

void mostrarRegistros(persona p[], int ce) {
    printf("Registros ordenados por numero de cuenta: \n\n");
    for (int i = 0; i < ce; i++) {
        printf("Persona %d:\n", i+1);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Apellido: %s\n", p[i].apellido);
        printf("Direccion: %s\n", p[i].direccion);
        printf("Telefono: %s\n", p[i].telefono);
        printf("Numero de cuenta: %04d\n", p[i].cuenta);
        printf("\n");
    }
}

int main(){
    persona personas[MAX];
    int ce;

    printf("Ingrese la cantidad de registros. Maximo %d", MAX);
    scanf("%d", &ce);
    getchar();

    leerPersonas(personas, ce);
    ordenarPersonas(personas, ce);
    mostrarRegistros(personas, ce);
}