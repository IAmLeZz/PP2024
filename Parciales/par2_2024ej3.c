//
// Created by Álvaro on 12/16/2024.
//
#include <stdio.h>

int devolverStockDeProducto(int productos[25][25], int producto, int numSucursales) {
    int stocktotal = 0;
    for (int j = 0; j<numSucursales; j++) {
        stocktotal += productos[producto][j];
    }
    return stocktotal;
}

int devolverMenorStock(int productos[25][25], int numSucursales, int numProductos) {
    int menorStock = 0;
    int menorSucursal = 0;

    for (int producto = 0; producto < numProductos; producto++) {
        menorStock += productos[producto][0];
    }

    for (int sucursal = 1; sucursal<numSucursales; sucursal++) {
        int totalStock = 0;
        for (int producto = 0; producto < numProductos; producto++) {
            totalStock += productos[sucursal][producto];
        }

        if (totalStock<menorStock) {
            menorStock = totalStock;
            menorSucursal = sucursal;
        }
    }
    return menorSucursal;
}

int main() {
    int stock[25][25] = {
        {190, 20, 15},  // Producto 0
        {5,  25, 10},  // Producto 1
        {7,  18, 12},  // Producto 2
    };
    int numProductos = 3;    // Número de productos
    int numSucursales = 3;   // Número de sucursales

    int menorSucursal = devolverMenorStock(stock, numSucursales, numProductos);
    printf("%d", menorSucursal);
}