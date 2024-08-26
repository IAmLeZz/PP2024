//
// Created by Álvaro on 8/26/2024.
//
#include <stdio.h>

int main() {
    double num1, num2, num3;
    double mayor, menor;

    // Leer los tres números
    printf("Ingrese el primer número: ");
    scanf("%lf", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%lf", &num2);
    printf("Ingrese el tercer número: ");
    scanf("%lf", &num3);

    // Determinar el mayor
    if (num1 >= num2 && num1 >= num3) {
        mayor = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        mayor = num2;
    } else {
        mayor = num3;
    }

    // Determinar el menor
    if (num1 <= num2 && num1 <= num3) {
        menor = num1;
    } else if (num2 <= num1 && num2 <= num3) {
        menor = num2;
    } else {
        menor = num3;
    }

    // Imprimir el resultado
    printf("El número mayor es: %.2lf\n", mayor);
    printf("El número menor es: %.2lf\n", menor);

    return 0;
}