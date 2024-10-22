//
// Created by Álvaro on 10/18/2024.
//
#include <stdio.h>
#define MAX 10

typedef struct {
    int numEquipo;
    char nombreEquipo[20];
    char nombreRepresentante[20];
} equipo;

typedef struct {
    int numEquipoA;
    int cantGolesEquipoA;
    int numEquipoB;
    int cantGolesEquipoB;

} partido;

typedef struct {
    int numEquipo;
    int puntos;
} puntos_equipo;

int obtenerIndice(equipo equipos[MAX], int numEquipo, int ce){
    int i =0;
    for(i = 0 ; i < ce; i++) {
        if (equipos[i].numEquipo == numEquipo) {
            return i;
        }
    }
    return  -1;
}

void leerEquipo(equipo equipos[MAX], int ce) {
    for(int i = 0; i < ce; i++) {
        printf("Cual es el numero del equipo? \n");
        scanf("%d", &equipos[i].numEquipo);
        getchar();
        printf("Cual es el nombre del equipo? \n");
        gets(equipos[i].nombreEquipo);
        printf("Cual es el nombre del representante? \n");
        gets(equipos[i].nombreRepresentante);
    }
}

void leerResultados(partido partidos[MAX], int ce) {
    for(int i = 0; i < ce; i++) {
        printf("Cual es el numero del equipo A? \n");
        scanf("%d", &partidos[i].numEquipoA);
        printf("Cuantos goles marcó el equipo A? \n");
        scanf("%d", &partidos[i].cantGolesEquipoA);
        printf("Cual es el numero del equipo B? \n");
        scanf("%d", &partidos[i].numEquipoB);
        printf("Cuantos goles marcó el equipo B? \n");
        scanf("%d", &partidos[i].cantGolesEquipoB);

    }
}

void imprimirResultados(equipo equipos[MAX], partido partidos[MAX], int ce) {
    for (int i = 0; i < ce; i++) {
        // Obtener los índices del equipo A y B
        int indiceA = obtenerIndice(equipos, partidos[i].numEquipoA, ce);
        int indiceB = obtenerIndice(equipos, partidos[i].numEquipoB, ce);

        if (indiceA != -1 && indiceB != -1) {
            // Imprimir el resultado del partido entre el equipo A y el equipo B
            printf("%s - %d : %d - %s\n",
                   equipos[indiceA].nombreEquipo,
                   partidos[i].cantGolesEquipoA,
                   partidos[i].cantGolesEquipoB,
                   equipos[indiceB].nombreEquipo);
        } else {
            printf("Error: Algún equipo no encontrado.\n");
        }
    }
}

void calcularPuntos(equipo equipos[MAX], partido partidos[MAX], int ce, puntos_equipo puntos[MAX]) {
    // Inicializar los puntos en 0
    for (int i = 0; i < ce; i++) {
        puntos[i].numEquipo = equipos[i].numEquipo;
        puntos[i].puntos = 0;
    }

    for (int i = 0; i < ce; i++) {
        // Obtener los índices del equipo A y B
        int indiceA = obtenerIndice(equipos, partidos[i].numEquipoA, ce);
        int indiceB = obtenerIndice(equipos, partidos[i].numEquipoB, ce);

        if (indiceA != -1 && indiceB != -1) {
            if (partidos[i].cantGolesEquipoA > partidos[i].cantGolesEquipoB) {
                puntos[indiceA].puntos +=3;
            } else if (partidos[i].cantGolesEquipoA < partidos[i].cantGolesEquipoB) {
                puntos[indiceB].puntos -= 3;
            } else {
                puntos[indiceA].puntos += 1;
                puntos[indiceB].puntos += 1;
            }
        } else {
            printf("Error: Algún equipo no encontrado.\n");
        }
    }
}

// Función para ordenar los equipos por puntos de mayor a menor
void ordenarPorPuntos(puntos_equipo puntos[MAX], equipo equipos[MAX], int ce) {
    puntos_equipo tempPuntos;
    equipo tempEquipo;

    for (int i = 0; i < ce - 1; i++) {
        for (int j = 0; j < ce - 1 - i; j++) {
            if (puntos[j].puntos < puntos[j + 1].puntos) {
                // Intercambiar puntos
                tempPuntos = puntos[j];
                puntos[j] = puntos[j + 1];
                puntos[j + 1] = tempPuntos;

                // Intercambiar equipos correspondientes
                tempEquipo = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = tempEquipo;
            }
        }
    }
}

// Función para imprimir el resultado final
void imprimirResultadosOrdenados(equipo equipos[MAX], puntos_equipo puntos[MAX], int ce) {
    printf("Nombre del Equipo       Puntos\n");
    for (int i = 0; i < ce; i++) {
        printf("%-20s %d\n", equipos[i].nombreEquipo, puntos[i].puntos);
    }
}

int main() {
    equipo equipos[MAX];
    int ce = 2;
    partido partidos[MAX];
    puntos_equipo puntos[MAX];

    leerEquipo(equipos, ce);
    leerResultados(partidos, ce);

    calcularPuntos(equipos, partidos, puntos, ce);
    ordenarPorPuntos(puntos, equipos, ce);

    imprimirResultadosOrdenados(equipos, puntos, ce);



}