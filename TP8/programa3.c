#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 100
#define ARCHIVO1 "numeros1.dat"
#define ARCHIVO2 "numeros2.dat"
#define ARCHIVO_MEZCLA "numeros_mezclados.dat"

// Función para escribir un arreglo de números enteros en un archivo
void escribirArchivo(int numeros[], int cantidad, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s para escribir.\n", nombreArchivo);
        exit(1);
    }

    fwrite(numeros, sizeof(int), cantidad, archivo);
    fclose(archivo);
}

// Función para leer los números ingresados por el usuario a un arreglo
int leerNumerosConsola(int numeros[], const char *mensaje) {
    int cantidad;
    printf("%s\n", mensaje);
    printf("¿Cuántos números desea ingresar? ");
    scanf("%d", &cantidad);

    printf("Ingrese los números en orden ascendente:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    return cantidad;
}

// Función para mezclar dos archivos de números enteros en uno solo en orden ascendente
void mezclarArchivos(int numeros1[], int cantidad1, int numeros2[], int cantidad2, int resultado[], int *cantidadResultado) {
    int i = 0, j = 0, k = 0;

    // Mezcla los dos arreglos de manera ordenada
    while (i < cantidad1 && j < cantidad2) {
        if (numeros1[i] < numeros2[j]) {
            resultado[k++] = numeros1[i++];
        } else {
            resultado[k++] = numeros2[j++];
        }
    }

    // Si quedan elementos en el primer arreglo, los añadimos
    while (i < cantidad1) {
        resultado[k++] = numeros1[i++];
    }

    // Si quedan elementos en el segundo arreglo, los añadimos
    while (j < cantidad2) {
        resultado[k++] = numeros2[j++];
    }

    *cantidadResultado = k;  // Almacena la cantidad total de elementos en el resultado
}

// Función para listar el contenido de un archivo
void listarArchivo(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s para listar.\n", nombreArchivo);
        exit(1);
    }

    int numero;
    printf("Contenido del archivo %s:\n", nombreArchivo);
    while (fread(&numero, sizeof(int), 1, archivo)) {
        printf("%d ", numero);
    }
    printf("\n");

    fclose(archivo);
}

int main() {
    int numeros1[MAX_NUMEROS], numeros2[MAX_NUMEROS], resultado[MAX_NUMEROS * 2];
    int cantidad1, cantidad2, cantidadResultado;

    // Leer los números desde la consola para ambos archivos
    cantidad1 = leerNumerosConsola(numeros1, "Ingrese los números para el archivo 1:");
    escribirArchivo(numeros1, cantidad1, ARCHIVO1);

    cantidad2 = leerNumerosConsola(numeros2, "Ingrese los números para el archivo 2:");
    escribirArchivo(numeros2, cantidad2, ARCHIVO2);

    // Mezclar los números de los dos archivos
    mezclarArchivos(numeros1, cantidad1, numeros2, cantidad2, resultado, &cantidadResultado);

    // Escribir el resultado de la mezcla en un nuevo archivo
    escribirArchivo(resultado, cantidadResultado, ARCHIVO_MEZCLA);

    // Listar el contenido de los tres archivos
    listarArchivo(ARCHIVO1);
    listarArchivo(ARCHIVO2);
    listarArchivo(ARCHIVO_MEZCLA);

    return 0;
}
