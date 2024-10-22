//
// Created by Álvaro on 10/14/2024.
//
#include <stdio.h>
#define MAX 50
#define SALDO_MINIMO -1500
typedef struct {
    int numCuenta;
    char nombreTitular[50];
    float saldo;
} cuentaBancaria;

int buscarCuenta(cuentaBancaria cuentas[MAX], int ce, int numCuenta) {
    for (int i = 0; i < ce; i++) {
        if (cuentas[i].numCuenta == numCuenta) {
            return i;
        }
    }
    return -1;
}
void crearCuenta(cuentaBancaria cuentas[], int *ce, int numeroCuenta) {
    if (*ce >= MAX) {
        printf("No se pueden crear mas cuentas. \n");
        return;
    }
    cuentas[*ce].numCuenta = numeroCuenta;
    printf("Ingrese el nombre del titular \n");
    getchar();
    gets(cuentas[*ce].nombreTitular);
    cuentas[*ce].saldo = 0;
    (*ce)++;
    printf("Cuenta creada con exito \n");

}

void modificarSaldo(cuentaBancaria cuentas[], int indice, float monto, char tipoOperacion) {
    if (tipoOperacion == 'D') {
        cuentas[indice].saldo += monto;
    } else if(tipoOperacion == 'R'){
        if (cuentas[indice].saldo - monto >= SALDO_MINIMO) {
            cuentas[indice].saldo -= monto;
            printf("Retiro realizado. Nuevo saldo %.2f\n", cuentas[indice].saldo);
        } else {
            printf("Operacion denegada. El saldo no puede ser menor a %d \n", SALDO_MINIMO);
        }
    }
}


void imprimirCuenta(cuentaBancaria cuenta) {
    printf("\nEstado de la cuenta:\n");
    printf("Número de cuenta: %d\n", cuenta.numCuenta);
    printf("Nombre del titular: %s\n", cuenta.nombreTitular);
    printf("Saldo actual: %.2f\n\n", cuenta.saldo);
}
int main() {
    cuentaBancaria cuentas[MAX];
    int ce = 0;
    int opcion, numCuenta, indice;
    float monto;
    char tipoOperacion;

    do {
        printf("1. Operar cuenta \n");
        printf("2. Imprimir estado de una cuenta\n");
        printf("3. Salir \n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el numero de la cuenta. \n");
                scanf("%d", &numCuenta);
                indice = buscarCuenta(cuentas, ce, numCuenta);

            if (indice == -1) {
                printf("La cuenta no existe. Deseas crear una? \n");
                getchar();
                char respuesta;
                scanf("%c", &respuesta);
                if (respuesta == 'S' || 's') {
                    crearCuenta(cuentas, &ce, numCuenta);
                } else {
                    printf("Operacion cancelada. \n");
                }
            } else {
                printf("Ingrese el monto de la operacion: \n");
                scanf("%f", &monto);
                printf("Ingrese el tipo de la operacion (D = deposito, R = retiro): \n");
                getchar();
                scanf("%c", &tipoOperacion);
                modificarSaldo(cuentas, indice, monto, tipoOperacion);
            }
            break;
            case 2:
                printf("Ingrese el numero de la cuenta \n");
                scanf("%d", &numCuenta);
                indice = buscarCuenta(cuentas, ce, numCuenta);
                if (indice != -1) {
                imprimirCuenta(cuentas[indice]);
                } else {
                    printf("La cuenta no existe. \n");
                }
            break;
            case 3:
                printf("Gracias por usar el programa! \n");
            break;
            default:
                printf("Opcion no valida. \n");

        }
    } while (opcion != 3);

    return 0;
}