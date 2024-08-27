//
// Created by Álvaro on 8/27/2024.
//
#include <stdio.h>

void imprimirDepartamento(int codigo) {
    int departamento = codigo / 1000;
    int curso = codigo % 1000;

    switch (departamento) {
        case 1:
            printf("Departamento: Biología\n");
        break;
        case 2:
            printf("Departamento: Química\n");
        break;
        case 3:
            printf("Departamento: Ciencias de la Computación\n");
        break;
        case 4:
            printf("Departamento: Geología\n");
        break;
        case 5:
            printf("Departamento: Matemática\n");
        break;
        case 6:
            printf("Departamento: Física\n");
        break;
        default:
            printf("Código de departamento no válido\n");
        return;
    }

    printf("Número de curso: %d\n", curso);
}

int main() {
    int codigo;

    printf("Introduce el código del curso (4 dígitos): ");
    scanf("%d", &codigo);

    imprimirDepartamento(codigo);

    return 0;
}