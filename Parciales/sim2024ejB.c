#include <stdio.h>
//
// Created by Álvaro on 9/28/2024.
//
int cargarSaldosNegativos(int clientes[], int saldos[], int saldosNegativos[]) {
    int j = 0;
    for (int i = 0; i < 5; i++) {
        if (saldos[i] < 0) {
            saldosNegativos[j] = clientes[i];
            j++;
        }
    }
    return j;
}
void mostrarClientesNegativos(int saldosNegativos[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay clientes con saldo negativo \n");
    } else {
        printf("Clientes con saldo negativo. \n");
        for (int i = 0; i < cantidad; i++) {
            printf("Cliente %d \n", saldosNegativos[i]);
        }
    }
}

int main(){
    int clientes[100] = {101,102,103,104,105};
    int saldos[100] = {456,98,-80,-900,5652};
    int saldosNegativos[100];

    int cantidadNegativos = cargarSaldosNegativos(clientes, saldos, saldosNegativos);
    mostrarClientesNegativos(saldosNegativos, cantidadNegativos);





}