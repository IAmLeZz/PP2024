//
// Created by Álvaro on 10/27/2024.
//
#include <stdio.h>
#define LONGITUD 30

typedef struct{
    char nombre [LONGITUD];
    int legajo, edad;
}trabajadores;

void carga_uno(trabajadores *dato) {
    printf("Ingrese el legajo del empleado. \n");
    scanf("%d", &dato->legajo);
    getchar();
    printf("Ingrese el nombre \n");
    gets(dato->nombre);
    printf("Ingrese la edad. \n");
    scanf("%d", &dato->edad);
    getchar();
}

int carga_datos(trabajadores datos[LONGITUD]) {
    int i = 0, stop = 0, nro, cont = 0;

    while((i<10)&& (stop!=1)) {
        carga_uno(&datos[i]);
        printf("\n¿Desea seguir cargando empleados?");
        printf("\nPresione 1 para continuar cargando empleados");
        printf("\nPresione 2 para finalizar la carga de empleados");
        printf("\n\nOPCION: ");
        scanf("%d",&nro);
        getchar();
        if(nro==1)
        {
            stop=0;
            cont++;
        }
        else
        {
            stop=1;
            cont++;
        }
        datos++;
        i++;
    }
    return cont;
}

void listarEmpleados(trabajadores *dato, int cantidad) {
    for(int i = 0; i < cantidad; i++) {
        printf("Legajo: %d \n", dato->legajo);
        printf("Nombre y apellido: %s \n", dato->nombre);
        printf("Edad: %d \n", dato->edad);
        dato++;
    }
}

void buscarTrabajador(trabajadores *dato, int cant, int legajo) {
    int i = 0, encontrado = 0;
    while(i<cant && encontrado == 0) {
        if(dato->legajo == legajo) {
            printf("Legajo: %d \n", dato->legajo);
            printf("Nombre y apellido: %s \n", dato->nombre);
            printf("Edad: %d \n", dato->edad);
            encontrado = 1;
        }
        i++;
        dato++;
    }
}

int main() {
    trabajadores emple[LONGITUD];
    trabajadores *dato;
    dato = emple;
    int op, cant = 0, legajo;

    do {
        printf("1. Cargar datos de empleado \n");
        printf("2. Listar todos los empleado \n");
        printf("3. Buscar un empleado \n");
        printf("4. Salir \n");
        printf("\n \n OPCION: ");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1:
                printf("\nIngrese empleados:\n");
                cant=carga_datos(dato);
                if(cant==1)
                    printf("\n:::::USTED HA CARGADO %d EMPLEADO\n",cant);
                else if(cant>=2)
                {
                    printf("\t:::::USTED HA CARGADO %d EMPLEADOS:::::\n\n",cant);
                }
            break;
            case 2:
                listarEmpleados(dato, cant);
                printf("\n***************************************************\n");
            break;
            case 3:
                printf("¿Cual es el legajo del empleado? \n");
                scanf("%d", &legajo);
                buscarTrabajador(dato, cant, legajo);
            break;
            case 4:
                printf("Gracias por usar el programa. \n");
            break;
            default:
                printf("Opción inválida. \n");

        }
    } while (op != 4);
}
