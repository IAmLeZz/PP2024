//
// Created by Álvaro on 10/20/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define ARCHIVO_PACIENTES "pacientes.dat"
#define ARCHIVO_PACIENTES_ENFERMEDAD "pacientes_enfermedad.dat"

typedef struct {
    int numEnfermedad;
    char nombreEnfermedad;
} enfermedad;

typedef struct {
    int numMedicamento;
    char nombreMedicamento[50];
    int dosis;
} medicamento;

typedef struct {
    int numHistoriaClinica;
    char apellidoNombre[50];
    char fechaNac[50];
    char sexo[5];
    enfermedad enfermedades[4];
    medicamento medicamentos[3];
    char obraSocial[20];
} paciente;

void crearArchivo(paciente pacientes[MAX], int cantidad) {
    FILE *archivo = fopen(ARCHIVO_PACIENTES, "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo. \n");
        exit(1);
    }
    fwrite(pacientes, sizeof(paciente), cantidad, archivo);
    fclose(archivo);

}

void filtrarPorEnfermedad(int numEnfermedad) {
    FILE *archivo = fopen(ARCHIVO_PACIENTES, "rb");
    FILE *archivoFiltrado = fopen(ARCHIVO_PACIENTES_ENFERMEDAD, "wb");
    paciente pacienteActual;
    int i = 0, encontrado = 0;
    if (archivo == NULL || archivoFiltrado == NULL) {
        printf("No se pudo abrir el archivo. \n");
        exit(1);
    }
    printf("Generando archivo con los pacientes que tienen la enfermedad %d...\n", numEnfermedad);

    while (fread(&pacienteActual, sizeof(paciente), 1, archivo)) {
        for(i = 0; i < 4; i++) {
            if(pacienteActual.enfermedades[i].numEnfermedad == numEnfermedad) {
                fwrite(&pacienteActual, sizeof(paciente), 1, archivoFiltrado);
                encontrado = 1;
                break;
            }
        }
    }
    fclose(archivo);
    fclose(archivoFiltrado);

    if(encontrado) {
        printf("Archivo de pacientes con la enfermedad %d generado correctamente en '%s'.\n", numEnfermedad, ARCHIVO_PACIENTES_ENFERMEDAD);
    } else {
        printf("No se encontraron pacientes con la enfermedad %d.\n", numEnfermedad);
    }

}



int buscarCliente(paciente pacientes[MAX], int ce, const char *nombrePaciente) {
    for (int i = 0; i < ce; i++) {
        if (strcmp(pacientes[i].apellidoNombre, nombrePaciente)  == 0) {
            return pacientes[i].numHistoriaClinica;
        }
    }
    return 0;
}


int leerPacientes(paciente pacientes[MAX]) {
    int cantidad = 0;
    int cantidadEnfermedades = 0;
    int cantidadMedicamentos = 0;
    printf("Cuantos pacientes desea ingresar? \n");
    scanf("%d", &cantidad);
    getchar();

    for(int i = 0; i < cantidad; i++) {
        pacientes[i].numHistoriaClinica = i+1;
        printf("Ingresa el apellido y nombre del paciente: \n");
        gets(pacientes[i].apellidoNombre);
        printf("Ingresa la fecha de nacimiento del paciente \n");
        gets(pacientes[i].fechaNac);
        printf("Ingresa el sexo del paciente (M o F) \n");
        gets(pacientes[i].sexo);
        printf("Cuantas enfermedades tiene? \n");
        scanf("%d", &cantidadEnfermedades);
        getchar();
        if (cantidadEnfermedades) {
            for(int j = 0; j < cantidadEnfermedades; j++) {
                printf("Ingresa el numero de la enfermedad %d: \n", j+1);
                scanf("%d", &pacientes[i].enfermedades[j].numEnfermedad);
            }
        }
        printf("Cuantos medicamentos debe tomar? \n");
        scanf("%d", &cantidadMedicamentos);
        if (cantidadMedicamentos) {
            for(int k = 0; k < cantidadMedicamentos; k++) {
                printf("Ingresa el numero del medicamento %d: \n", k+1);
                scanf("%d", &pacientes[i].medicamentos[k].numMedicamento);
                printf("Ingrese la cantidad de dosis: \n");
                scanf("%d", &pacientes[i].medicamentos[k].dosis);
            }
        }
        getchar();
        printf("Que obra social tiene? \n");
        gets(pacientes[i].obraSocial);
    }
    return cantidad;
}

void modificarPaciente(paciente pacientes[MAX], int numHistoriaClinica) {
    paciente pacienteMod;
    int encontrado = 0;
    int cantEnfermedades = 0;
    int cantMedicamentos = 0;
    int op = 0;

    FILE *archivo = fopen(ARCHIVO_PACIENTES, "rb+");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Buscar el paciente en el archivo por número de historia clínica
    while (fread(&pacienteMod, sizeof(paciente), 1, archivo)) {
        if (pacienteMod.numHistoriaClinica == numHistoriaClinica) {
            encontrado = 1;
            break;  // Paciente encontrado, salimos del bucle
        }
        printf("Hubo un error. \n");

    }

    if (!encontrado) {
        printf("Paciente con número de historia clínica %d no encontrado.\n", numHistoriaClinica);
        fclose(archivo);
        return;
    }
    do {
            printf("¿Que desea modificar del paciente %s? \n", pacienteMod.apellidoNombre);
            printf("1. Enfermedades \n");
            printf("2. Medicamentos \n");
            printf("3. Obra social \n");
            printf("4. Salir \n");

            scanf("%d", &op);
            switch (op) {
                case 1:
                    printf("¿Cuantas enfermedades posee el paciente actualmente? \n");
                    scanf("%d", &cantEnfermedades);
                    if (cantEnfermedades) {
                        for(int i = 0; i < cantEnfermedades; i++) {
                            printf("Ingrese el num de la enfermedad %d: \n", i+1);
                            scanf("%d", &pacienteMod.enfermedades[i].numEnfermedad);
                        }
                }   else {
                    printf("El paciente se encuentra curado. \n");
                    }
                break;

                case 2:
                    printf("¿Cuantos medicamentos necesita el paciente actualmente? \n");
                scanf("%d", &cantMedicamentos);
                if (cantMedicamentos) {
                    for(int i = 0; i < cantMedicamentos; i++) {
                        printf("Ingrese el num del medicamento %d: \n", i+1);
                        scanf("%d", &pacienteMod.medicamentos[i].numMedicamento);
                        printf("Cantidad de dosis del medicamento: \n");
                        scanf("%d", &pacienteMod.medicamentos[i].dosis);
                    }
                } else {
                    printf("El paciente no necesita medicamentos. \n");
                }
                break;

                case 3:
                    printf("Cual es la nueva obra social del cliente?: \n");
                gets(pacienteMod.obraSocial);
                getchar();
                break;

                case 4:
                    printf("Los datos han sido actualizados. \n");
                break;

                default:
                    printf("Opcion invalida. \n");
            }
    } while (op != 4);
    fseek(archivo, -sizeof(paciente), SEEK_CUR);
    fwrite(&pacienteMod, sizeof(paciente), 1, archivo);
    fclose(archivo);
}

void listarPacientes() {
    FILE *archivo = fopen(ARCHIVO_PACIENTES, "rb");
    if (archivo == NULL) {
        printf("Archivo no encontrado.\n");
        exit(1);
    }

    paciente pacientes;
    printf("Num - Apellido Nombre - Fecha Nacimiento - Sexo - Enfermedades - Medicamentos - Obra Social\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(&pacientes, sizeof(paciente), 1, archivo)) {
        printf("%-8d %-30s %-12s %-7s ",
            pacientes.numHistoriaClinica,
            pacientes.apellidoNombre,
            pacientes.fechaNac,
            pacientes.sexo);

        // Mostrar enfermedades (solo las que existan)
        printf("Enfermedades: ");
        for (int i = 0; i < 4; i++) {
            if (pacientes.enfermedades[i].numEnfermedad > 0 && pacientes.enfermedades[i].numEnfermedad < 100) {
                printf("%d, ", pacientes.enfermedades[i].numEnfermedad);
            }
        }
        printf(" - Medicamentos: ");

        // Mostrar medicamentos (solo los que existan)
        for (int i = 0; i < 3; i++) {
            if (pacientes.medicamentos[i].numMedicamento > 0 && pacientes.medicamentos[i].numMedicamento < 100) {
                printf("%d (dosis: %d), ", pacientes.medicamentos[i].numMedicamento, pacientes.medicamentos[i].dosis);
            }
        }

        // Mostrar obra social (si tiene)
        if (pacientes.obraSocial[0] != '\0') {
            printf("- Obra social: %s\n", pacientes.obraSocial);
        } else {
            printf("- Sin obra social\n");
        }
    }

    fclose(archivo);
}


int main() {
    paciente pacientes[MAX];
    char pacienteBuscar[50];
    char respuesta[3];
    int pacienteAModificar;
    int numHistoria;
    int cantidad;
    int opcion;

do {
    // Menú de opciones principales
    printf("\n--- Menu de Opciones ---\n");
    printf("1. Registrar Pacientes\n");
    printf("2. Listar Pacientes\n");
    printf("3. Buscar Paciente\n");
    printf("4. Modificar Paciente\n");
    printf("5. Filtrar Pacientes por Enfermedad\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    getchar();  // Limpiar el buffer de entrada

    switch (opcion) {
        case 1:
            cantidad = leerPacientes(pacientes);
            crearArchivo(pacientes, cantidad);
            printf("Pacientes registrados exitosamente.\n");
            break;
        case 2:
            listarPacientes();
            break;
        case 3:
            printf("Ingresa el apellido y nombre exacto del paciente a buscar: ");
            gets(pacienteBuscar);
            numHistoria = buscarCliente(pacientes, cantidad, pacienteBuscar);
            if (numHistoria != 0) {
                printf("El número de historia clínica de %s es %d\n", pacienteBuscar, numHistoria);
            } else {
                printf("Paciente no encontrado.\n");
            }
            break;
        case 4:
            printf("Desea modificar un paciente? S/N: ");
            gets(respuesta);
            if (strcasecmp(respuesta, "S") == 0) {
                printf("Ingrese el número de historia clínica del paciente a modificar: ");
                scanf("%d", &pacienteAModificar);
                getchar();  // Limpiar el buffer de entrada
                modificarPaciente(pacientes, pacienteAModificar);
            } else {
                printf("Modificación cancelada.\n");
            }
            break;
        case 5:
            printf("Ingrese el número de la enfermedad por la que desea filtrar: ");
            int enfermedadBuscada;
            scanf("%d", &enfermedadBuscada);
            getchar();  // Limpiar el buffer de entrada
            filtrarPorEnfermedad(enfermedadBuscada);
            break;
        case 6:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no válida. Intente nuevamente.\n");
    }

} while (opcion != 6);

    return 0;

}