//
// Created by Álvaro on 10/14/2024.
//
#include <stdio.h>
#define MAX 50

typedef struct {
    int  numVuelo;
    char lineaAerea[30];
    char horaLlegada[30];
    char procedencia[30];
    char horaSalida[30];
    char destino[30];
} vuelo;

void ordenarVuelos(vuelo vuelos[MAX], int ce) {
    vuelo aux;
    for(int i = 0; i < ce; i++) {
        for(int j = 0; j < ce-1; j++) {
            if (vuelos[j].numVuelo > vuelos[j+1].numVuelo) {
                aux = vuelos[j];
                vuelos[j] = vuelos[j+1];
                vuelos[j+1] = aux;
            }
        }
    }
}

void imprimirVuelos(vuelo vuelos[MAX], int ce) {
    printf("Lista de vuelos ordenados por número de vuelo:\n");
    printf("--------------------------------------------------------------\n");
    printf("Num. Vuelo | Línea Aérea | Llegada | Procedencia | Salida | Destino\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < ce; i++) {
        printf("%10d | %-12s | %-6s | %-10s | %-6s | %-10s\n",
           vuelos[i].numVuelo,
           vuelos[i].lineaAerea,
           vuelos[i].horaLlegada,
           vuelos[i].procedencia,
           vuelos[i].horaSalida,
           vuelos[i].destino);
    }
}

int main() {
    vuelo vuelos[MAX] = {
        {123, "Aerolinea 1", "14:00", "Buenos Aires", "15:30", "Madrid"},
        {101, "Aerolinea 2", "10:00", "Lima", "11:45", "París"},
        {250, "Aerolinea 3", "12:00", "Nueva York", "13:20", "Berlín"},
        {145, "Aerolinea 4", "08:30", "Londres", "09:50", "Tokio"},
        {210, "Aerolinea 5", "16:15", "Santiago", "18:00", "Miami"}
    };
    int ce = 5;
    ordenarVuelos(vuelos, ce);
    imprimirVuelos(vuelos, ce);




}