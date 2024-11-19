#include <stdio.h>
//
// Created by Álvaro on 11/9/2024.
//
typedef struct {
    int legajo;
    char nombre[25];
} emple;

void carga_uno(emple *dato) {
    printf("Ingrese el legajo del empleado. \n");
    scanf("%d", &dato->legajo);
    getchar();
    printf("Ingrese el nombre del empleado. \n");
    gets(dato->nombre);
}
int carga_emples(emple personal[]) {
    int i = 0, stop = 0, count = 0, nro= 0;
    while((i < 10) && (stop == 0)) {
        carga_uno(&personal[i]);
        printf("Desea seguir cargando?");
        printf("\nPresione 1 para continuar cargando empleados");
        printf("\nPresione 2 para finalizar la carga de empleados");
        printf("\n\nOPCION: ");
        scanf("%d",&nro);
        getchar();
        if (nro == 1) {
            stop = 0;
            count++;
        } else {
            stop = 1;
            count++;
        }
        i++;
    }
return count;
}
int main() {
    emple empleados[25];
    emple *dato;
    dato = empleados;

    int cant = carga_emples(dato);

    for(int i = 0; i < cant; i++) {
        printf("Empleado n %d \n", i+1);
        printf("Legajo %d \n", dato->legajo);
        printf("Nombre %s \n", dato->nombre);
        dato++;
    }
}
