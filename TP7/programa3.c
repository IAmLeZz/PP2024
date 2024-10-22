//
// Created by Álvaro on 10/11/2024.
//
#include <stdio.h>
#include <string.h>
#define MAX 100
#define PAUSA 5

typedef struct {
    char nombre[30];
    char apellido[30];
    char sexo[2];
    int  edad;
} persona;
void calcularHyM(persona p[10], int ce, int *hombres, int *mujeres) {
    *hombres = 0;
    *mujeres = 0;
    for(int i = 0; i < ce; i++) {
        if (strcmp(p[i].sexo, "M") == 0) {
            (*hombres)++;
        } else if (strcmp(p[i].sexo, "F") == 0) {
            (*mujeres)++;
        }
    }
}

void mujeresMayor25Menor50(persona p[10], int ce) {
    for(int i = 0; i < ce; i++) {
        if (strcmp(p[i].sexo, "F") == 0 && p[i].edad > 25 && p[i].edad < 50) {
            printf("Mujer mayor a 25 y menor que 25 : %s %s \n", p[i].nombre, p[i].apellido);
        }
    }
}

void mostrarLista(persona p[10], int ce) {
    int contador = 0;
    for(int i = 0 ; i < ce; i ++) {
        printf("(%d) Nombre: %s %s, Edad: %d, Sexo: %s \n", i+1, p[i].nombre, p[i].apellido, p[i].edad, p[i].sexo);
        contador++;
        if (contador == PAUSA) {
            printf("Presiona <enter> para continuar... \n");
            getchar();
            contador = 0;
        }
    }
}

void mostrarFicha(persona p[10], int ce) {
    for(int i = 0; i < ce; i++) {
        printf("Nombre: %s \n", p[i].nombre);
        printf("Apellido: %s \n", p[i].apellido);
        printf("Edad: %d \n", p[i].edad);
        printf("Sexo: %s \n", p[i].sexo);
        printf("Presiona <enter> para continuar... \n");
        getchar();
    }
}

int main() {
    int ce, mujeres, hombres;
    persona personas[MAX];

    printf("Ingrese la cantidad de personas: \n");
    scanf("%d", &ce);
    getchar();

    for(int i = 0; i < ce; i++) {
        printf("Ingresa el nombre de la persona %d \n", i+1);
        gets(personas[i].nombre);
        printf("Ingresa el apellido de la persona %d \n", i+1);
        gets(personas[i].apellido);
        printf("Ingresa la edad de la persona %d \n", i+1);
        scanf("%d", &personas[i].edad);
        getchar();
        printf("Ingresa el sexo de la persona %d. M/F \n", i+1);
        gets(personas[i].sexo);


    }

    calcularHyM(personas, ce, &hombres, &mujeres);
    printf("Cantidad de hombres y mujeres: %d y %d \n", hombres, mujeres);
    mujeresMayor25Menor50(personas, ce);
    printf("Lista de personas \n");
    mostrarLista(personas, ce);
    printf("Mostrar el vector en formato tipo ficha \n");
    mostrarFicha(personas, ce);
}