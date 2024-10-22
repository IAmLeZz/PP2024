//
// Created by Álvaro on 10/21/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO_HORARIOS "horarios.dat"
#define ARCHIVO_EMPLEADOS "empleados.dat"
#define ARCHIVO_EMPLEADOS_TEMP "empleados_temp.dat"

#define MAX 100

typedef struct {
    int legajo;
    char fecha[50];
    char horaIngreso[50];
    char horaEgreso[50];
} horario;

typedef struct {
    int legajo;
    char apellidoNombre[50];
    int DNI;
    char domicilio[50];
} empleado;

void registrarEmpleados(empleado empleados[MAX], int cantidad) {
    FILE *archivo = fopen(ARCHIVO_EMPLEADOS, "ab");
    if (archivo == NULL) {
        printf("Hubo un error creando el archivo. \n");
        exit(1);
    }

    for (int i = 0; i < cantidad; i++) {
        fwrite(&empleados[i], sizeof(empleado), 1, archivo);
    }
    fclose(archivo);
}

int buscarEmpleado(empleado empleados[MAX], int cantidad, int legajo) {
    for (int i = 0; i < cantidad; i++) {
        if(empleados[i].legajo == legajo) {
            return i;
        }
    }
    return -1;
}

void eliminarEmpleado(int legajo) {
    int encontrado = 0;
    empleado empleadoAEliminar;
    FILE *archivo = fopen(ARCHIVO_EMPLEADOS, "rb+");
    FILE *archivoTemp = fopen(ARCHIVO_EMPLEADOS_TEMP, "wb");

    if (archivo == NULL || archivoTemp == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

   while (fread(&empleadoAEliminar, sizeof(empleado), 1, archivo)) {
       if (empleadoAEliminar.legajo != legajo) {
           fwrite(&empleadoAEliminar, sizeof(empleado), 1, archivoTemp);
       } else {
           encontrado = 1;
       }
   }

    fclose(archivo);
    fclose(archivoTemp);

    if (encontrado) {
        remove(ARCHIVO_EMPLEADOS);
        rename(ARCHIVO_EMPLEADOS_TEMP, ARCHIVO_EMPLEADOS);
        printf("El empleado con legajo %d fue eliminado \n", legajo);
    } else {
        printf("El empleado con legajo %d no fue encontrado \n.", legajo);
        remove(ARCHIVO_EMPLEADOS_TEMP);
    }

}

void modificarEmpleado(int legajo) {
    empleado empleadoMod;
    int encontrado = 0, op = 0;

    FILE *archivo = fopen(ARCHIVO_EMPLEADOS, "rb+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo. \n");
        return;
    }
    while (fread(&empleadoMod, sizeof(empleado), 1, archivo)) {
        if (empleadoMod.legajo == legajo) {
            encontrado = 1;
            break;
        }
        printf("Hubo un error. El legajo no existe %d \n", legajo);
    }
    if (!encontrado) {
        printf("El empleado con legajo %d no fue encontrado. \n", legajo);
        return;
    }

    do {
        printf("Que cambios desea realizar en el empleado con legajo %d? \n", legajo);
        printf("1. Cambiar apellido y nombre. \n");
        printf("2. Cambiar domicilio. \n");
        printf("3. Salir. \n");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                printf("Cual es el nuevo nombre del empleado?: \n");
                gets(empleadoMod.apellidoNombre);
            break;

            case 2:
                printf("Cual es su nuevo domicilio? \n");
                gets(empleadoMod.domicilio);
            break;
            case 3:
                printf("Los datos han sido actualizados. Saliendo... \n");
            break;
            default:
                printf("Opcion invalida! \n");
        }
    } while (op != 3);

    fseek(archivo, -sizeof(empleado), SEEK_CUR);
    fwrite(&empleadoMod, sizeof(empleado), 1, archivo);
    fclose(archivo);

}
void listarEmpleados() {
    empleado empleadoActual;
    FILE *archivo = fopen(ARCHIVO_EMPLEADOS, "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de empleados.\n");
        return;
    }
5
    printf("Legajo\tApellido y Nombres\t\tDNI\t\tDomicilio\n");
    printf("-------------------------------------------------------------\n");

    // Lee cada empleado y lo muestra
    while (fread(&empleadoActual, sizeof(empleado), 1, archivo)) {
        printf("%d\t%-25s\t%d\t%s\n", empleadoActual.legajo, empleadoActual.apellidoNombre, empleadoActual.DNI, empleadoActual.domicilio);
    }

    fclose(archivo);
}

void modificarHorario(int legajo) {
    horario horarioEmpleado;
    int encontrado = 0;

    FILE *archivoHorario = fopen(ARCHIVO_HORARIOS, "rb+");
    if (archivoHorario == NULL) {
        printf("Error al abrir el archivo. \n");
        exit(1);
    }
    while (fread(&horarioEmpleado, sizeof(horario), 1, archivoHorario)) {
        if (horarioEmpleado.legajo == legajo) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("Va a actualizar el horario del legajo %d \n", legajo);
        printf("Ingrese la fecha de hoy dd/mm/yy \n");
        gets(horarioEmpleado.fecha);

        printf("Ingrese la hora de ingreso HH:MM \n");
        gets(horarioEmpleado.horaIngreso);

        printf("Ingrese la hora de egreso HH:MM \n");
        gets(horarioEmpleado.horaEgreso);

        fseek(archivoHorario, -sizeof(horario), SEEK_CUR);
        fwrite(&horarioEmpleado, sizeof(horario), 1, archivoHorario);
        printf("Horario actualizado para el legajo %d \n", legajo);
    } else {
        printf("No se encontró el legajo %d \n", legajo);
    }
    fclose(archivoHorario);

}

void ingresarHorario(int legajo) {
    horario horarioEmpleado;
    int encontrado = 0;
    char actualizar[3];

    FILE *archivoHorario = fopen(ARCHIVO_HORARIOS, "ab+");
    if (archivoHorario == NULL) {
        printf("Error al abrir el archivo. \n");
        exit(1);
    }
    while (fread(&horarioEmpleado, sizeof(horario), 1, archivoHorario)) {
        if (horarioEmpleado.legajo == legajo) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        horarioEmpleado.legajo = legajo;
        printf("Ingrese la fecha dd/mm/yy \n");
        gets(horarioEmpleado.fecha);

        printf("Ingrese la hora de ingreso HH:MM \n");
        gets(horarioEmpleado.horaIngreso);

        printf("Ingrese la hora de egreso HH:MM \n");
        gets(horarioEmpleado.horaEgreso);

        fwrite(&horarioEmpleado, sizeof(horario), 1, archivoHorario);
        printf("Horario registrado para el legajo %d \n", legajo);
        fclose(archivoHorario);
    } else {
        fclose(archivoHorario);
        printf("El horario del legajo %d ya se encuentrado registrado. \n", legajo);
        printf("Desea actualizarlo? S/N \n");
        gets(actualizar);
        if (strcasecmp(actualizar, "S")==0) {
            modificarHorario(legajo);
        } else {
            printf("No se actualizo ningun horario... \n");
        }

    }


}


void mostrarListado(const char* fechaFiltro) {
    FILE *archivoEmpleados = fopen(ARCHIVO_EMPLEADOS, "rb");
    FILE *archivoHorarios = fopen(ARCHIVO_HORARIOS, "rb");
    empleado empleados[MAX];
    horario horarios[MAX];

    int cantidadHorarios = 0, cantidadEmpleados = 0;
    if (archivoEmpleados == NULL || archivoHorarios == NULL) {
        printf("Hubo un error. Uno o ambos archivos no existen \n");
        exit(1);
    }
    while (fread(&horarios[cantidadHorarios], sizeof(horario), 1, archivoHorarios)) {
      cantidadHorarios++;
    }

    while (fread(&empleados[cantidadEmpleados], sizeof(empleado), 1, archivoEmpleados)) {
        cantidadEmpleados++;
    }
    fclose(archivoEmpleados);
    fclose(archivoHorarios);

    printf("Legajo\tApellido y Nombres\t\tFecha\t\tHora de Ingreso\tHora de Egreso\n");
    printf("-----------------------------------------------------------------------------\n");

    for(int i = 0; i < cantidadHorarios; i++) {
        if (strcmp(horarios[i].fecha, fechaFiltro) >= 0) {
            for(int j = 0; j < cantidadEmpleados; j++) {
                if(empleados[j].legajo == horarios[i].legajo) {
                    printf("%d\t%-25s\t%-10s\t%-10s\t%-10s\n", empleados[j].legajo, empleados[j].apellidoNombre,
                           horarios[i].fecha, horarios[i].horaIngreso, horarios[i].horaEgreso);
                }
            }
        }
    }
}

int main() {
    int opcion, legajo, cantidad;
    char fechaFiltro[50];
    empleado empleados[MAX];

    do {
        printf("\n--- Menú de Gestión de Empleados y Horarios ---\n");
        printf("1. Registrar empleados\n");
        printf("2. Eliminar empleado\n");
        printf("3. Modificar empleado\n");
        printf("4. Ingresar horario\n");
        printf("5. Mostrar horarios desde una fecha\n");
        printf("6. Listar empleados\n");
        printf("7. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        getchar();  // Consumir salto de línea después de scanf

        switch(opcion) {
            case 1:
                printf("Ingrese la cantidad de empleados a registrar: ");
                scanf("%d", &cantidad);
                for (int i = 0; i < cantidad; i++) {
                    printf("Ingrese el legajo del empleado %d: ", i+1);
                    scanf("%d", &empleados[i].legajo);
                    getchar();
                    printf("Ingrese el apellido y nombre del empleado: ");
                    gets(empleados[i].apellidoNombre);
                    printf("Ingrese el DNI del empleado: ");
                    scanf("%d", &empleados[i].DNI);
                    getchar();
                    printf("Ingrese el domicilio del empleado: ");
                    gets(empleados[i].domicilio);
                }
                registrarEmpleados(empleados, cantidad);
                printf("Empleados registrados correctamente.\n");
                break;

            case 2:
                printf("Ingrese el legajo del empleado a eliminar: ");
                scanf("%d", &legajo);
                getchar();
                eliminarEmpleado(legajo);
                break;

            case 3:
                printf("Ingrese el legajo del empleado a modificar: ");
                scanf("%d", &legajo);
                getchar();
                modificarEmpleado(legajo);
                break;

            case 4:
                printf("Ingrese el legajo del empleado para registrar/modificar horario: ");
                scanf("%d", &legajo);
                getchar();
                ingresarHorario(legajo);
                break;

            case 5:
                printf("Ingrese la fecha desde la cual quiere listar (dd/mm/yy): ");
                scanf("%s", fechaFiltro);
                mostrarListado(fechaFiltro);
                break;
            case 6:
                // Opción para listar todos los empleados
                    listarEmpleados();
            break;

            case 7:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida, por favor intente de nuevo.\n");
                break;
        }

    } while (opcion != 7);

    return 0;
}