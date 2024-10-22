//
// Created by Álvaro on 10/17/2024.
//
#include <stdio.h>
#define MAX 50

typedef struct {
    int minutos;
    int segundos;
} s_tiempo;

typedef struct {
    int nro_corredor;
    // guarda nro de corredor
    s_tiempo tiempo;
    // guarda el tiempo que tardo el corredor
} carrera;

typedef struct {
    int  nro_corredor;  // guarda nro de corredor
    char apellido[30];
    char nombres[30];
    char direccion[30];
} datos;

void leerMaratonistas(datos maratonistas[MAX], int ce) {
    for(int i = 0; i < ce; i++) {
        printf("Ingresa el numero del corredor. \n");
        scanf("%d", &maratonistas[i].nro_corredor);
        getchar();
        printf("Ingresa el apellido del corredor \n");
        gets(maratonistas[i].apellido);
        printf("Ingresa el nombre \n");
        gets(maratonistas[i].nombres);
        printf("Ingresa la direccion \n");
        gets(maratonistas[i].direccion);
    }
}

void leerResultados(datos maratonistas[MAX], carrera resultado[MAX], int ce) {
    for(int i = 0; i < ce; i++) {
        resultado[i].nro_corredor = maratonistas[i].nro_corredor;
        printf("Cual fue el resultado del maratonista %d en minutos?: \n", resultado[i].nro_corredor);
        scanf("%d", &resultado[i].tiempo.minutos);
        printf("Cual fue el resultado del maratonista %d en segundos?: \n", resultado[i].nro_corredor);
        scanf("%d", &resultado[i].tiempo.segundos);
    }
}

void ordenarResultados(datos maratonistas[MAX], carrera resultado[MAX], int ce) {
    int i, j;
    datos tempDatos;
    carrera tempCarrera;

    for (i = 0; i < ce - 1; i++) {
        for (j = 0; j < ce - 1 - i; j++) {
            if ((resultado[j].tiempo.minutos > resultado[j + 1].tiempo.minutos) ||
                (resultado[j].tiempo.minutos == resultado[j + 1].tiempo.minutos &&
                 resultado[j].tiempo.segundos > resultado[j + 1].tiempo.segundos)) {
                // Intercambio de resultados
                tempCarrera = resultado[j];
                resultado[j] = resultado[j + 1];
                resultado[j + 1] = tempCarrera;

                // Intercambio de datos de maratonistas correspondientes
                tempDatos = maratonistas[j];
                maratonistas[j] = maratonistas[j + 1];
                maratonistas[j + 1] = tempDatos;
                 }
        }
    }
}

void imprimirResultados(datos maratonistas[MAX], carrera resultado[MAX], int ce) {
    printf("Posición | Nro Corredor | Tiempo (min:seg) | Apellido | Nombres\n");
    printf("---------|--------------|------------------|------------|-----------\n");
    for (int i = 0; i < ce; i++) {
        printf("%8d | %-12d | %4d:%02d           | %-10s | %-12s\n",
               i + 1,
               resultado[i].nro_corredor,
               resultado[i].tiempo.minutos,
               resultado[i].tiempo.segundos,
               maratonistas[i].apellido,
               maratonistas[i].nombres);
    }
}

int main() {
    datos maratonistas[MAX];
    int ce = 2;
    carrera resultadoCarrera[MAX];

    leerMaratonistas(maratonistas, ce);
    leerResultados(maratonistas, &resultadoCarrera, ce);
    ordenarResultados(maratonistas, &resultadoCarrera, ce);
    imprimirResultados(maratonistas, &resultadoCarrera, ce);



}