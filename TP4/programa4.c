//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>

// Función que verifica si un carácter es un dígito de 0 a 9
int digito(char c) {
    if (c >= '0' && c <= '9') {
        return 1; // Es un dígito
    } else {
        return 0; // No es un dígito
    }
}

int main() {
    char caracter;

    // Pedir al usuario que ingrese un carácter
    printf("Introduce un carácter: ");
    scanf("%c", &caracter);

    // Llamar a la función para verificar si es un dígito
    if (digito(caracter)) {
        printf("El carácter '%c' es un dígito.\n", caracter);
    } else {
        printf("El carácter '%c' no es un dígito.\n", caracter);
    }

    return 0;
}
