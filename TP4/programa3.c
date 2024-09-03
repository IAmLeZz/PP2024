//
// Created by Álvaro on 8/28/2024.
//
#include <stdio.h>

// Función que verifica si uno de los números divide al otro
int esDivisible(int a, int b) {
    // Verifica si 'a' divide a 'b' o si 'b' divide a 'a'
    if (a != 0 && b % a == 0) {
        return 1; // 'a' divide a 'b'
    } else if (b != 0 && a % b == 0) {
        return 1; // 'b' divide a 'a'
    } else {
        return 0; // Ninguno divide al otro
    }
}

int main() {
    int num1, num2;
    int resultado;

    // Pedir al usuario que ingrese dos números enteros
    printf("Introduce el primer numero entero: ");
    scanf("%d", &num1);
    printf("Introduce el segundo numero entero: ");
    scanf("%d", &num2);

    // Llamar a la función para verificar la divisibilidad
    resultado = esDivisible(num1, num2);

    // Imprimir el resultado
    if (resultado == 1) {
        printf("Uno de los numeros divide al otro.\n");
    } else {
        printf("Ninguno de los numeros divide al otro.\n");
    }

    return 0;
}
