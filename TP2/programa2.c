#include <stdio.h>

int main() {
    float ventas, comision = 0, sueldo_bruto, obra_social, jubilacion, sueldo_neto;
    const float basico = 1800.0;

    // Leer la cantidad de dinero de las ventas a comisión
    printf("Ingrese la cantidad de dinero producto de ventas a comision: ");
    scanf("%f", &ventas);

    // Calcular la comisión según la cantidad de ventas
    if (ventas < 10000) {
        comision = ventas * 0.02;
    } else if (ventas < 50000) {
        comision = ventas * 0.035;
    } else {
        comision = ventas * 0.05;
    }

    // Calcular el sueldo bruto (Básico + Comisión)
    sueldo_bruto = basico + comision;

    // Calcular los descuentos
    obra_social = sueldo_bruto * 0.035;
    jubilacion = sueldo_bruto * 0.11;

    // Calcular el sueldo neto
    sueldo_neto = sueldo_bruto - obra_social - jubilacion;

    // Imprimir los resultados con el formato solicitado
    printf("Sueldo Bruto: %.2f\n", sueldo_bruto);
    printf("Obra Social: %.2f\n", obra_social);
    printf("Jubilación: %.2f\n", jubilacion);
    printf("Sueldo Neto: %.2f\n", sueldo_neto);

    return 0;
}