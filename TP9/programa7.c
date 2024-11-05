//
// Created by Álvaro on 11/4/2024.
//
#include <stdio.h>
#include <math.h>
#define MAX 100

int multiplicar(int n, int b) {
    if (b ==0) {
        return 0;
    }
    if (b>0) {
        return n+multiplicar(n,b-1);
    }
    return -multiplicar(n, -b);
}
int contarDigs(int num) {
    if (num < 10) {
        return 1;
    }
    return 1 + contarDigs(num/10);
}
int digitoMasSignificativo(int num) {
    if (num < 10) {
        return num;
    }
    return digitoMasSignificativo(num/10);
}

int kDigito(int numero, int k) {
    int totalDigitos = contarDigs(numero);

    if (k > totalDigitos || k <= 0) {
        return -1;
    }
    if (k == totalDigitos) {
        return numero%10;
    }
    return kDigito(numero/10, k);
}

int MCD(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }

    if (a == b) {
        return a;
    }
    if (a>b) {
        return MCD(a-b, b);
    }
    return MCD(a, b-a);
}

int buscarElemento(int v[MAX], int pos, int k) {
    if (v[pos] == k) {
        printf("Se encontro %d en la posición %d del arreglo \n", k, pos);
        return pos;
    }
    if (pos > MAX) {
        return -1;
    }
    return buscarElemento(v, pos+1, k);

}

int ocurrenciasString(char* texto, char c) {
    int res = 0;
    if(*texto !='\0' ) {
        if (*texto == c) {
            res=1;
        }
        res+=ocurrenciasString(texto+1, c);
    }
    return res;
}

int calcularTamañoString(char *texto) {
    int res = 0;
    if (*texto != '\0') {
        res = 1;
        res+=calcularTamañoString(texto+1);
    }
    return res;
}

int busquedaBinaria(int v[MAX], int inic, int fin, int elem) {

    if (inic > fin) {
        return -1;
    }

    int medio = inic + (fin-inic)/2;
    if (v[medio] == elem) {
        return medio;
    }

    if (v[medio]>elem) {
        return busquedaBinaria(v, inic, medio-1, elem);
    }
    return busquedaBinaria(v, inic, medio+1, elem);
}

int ordenarSeleccion(int v[MAX], int n, int i) {
    int min = i;
    for(int j = i+1; j < n; j++) {
        if (v[j] < v[min]) {
            min = j;
        }
    }

    int temp = v[min];
    v[min] = v[i];
    v[i] = temp;

    if (i +1 < n) {
        ordenarSeleccion(v, n, i+1);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int mul = multiplicar(4,3);

    int v[10] = {23, 10, 38, 22, 9};
    int tamV = sizeof(v) / sizeof(v[0]);
    printf("%d \n", mul);

    int digito = kDigito(1570,3);
    printf("%d \n", digito);

    int a = 50, b = 75, k = 22;
    int c = MCD(a, b);
    printf("%d \n", c);


    int resultado = buscarElemento(v, 0, k);
    if (resultado == -1) {
        printf("El elemento %d no se encontró en el arreglo.\n", k);
    }
    char texto[MAX] = "Holaaa que tal";
    int ocurrencias = ocurrenciasString(texto, 'a');
    printf("%d \n", ocurrencias);

    int tamañoString = calcularTamañoString(texto);
    int mitadBin = busquedaBinaria(v, 0, tamV-1, 9);
    printf("%d \n", tamañoString);

    printf("%d \n", mitadBin);

    int vector2[] = {15, 69, 20, 13, 19, 2, 10};
    int tam = sizeof(vector2)/sizeof(vector2[0]);

    ordenarSeleccion(vector2, tam, 0);
    printArray(vector2, tam);



}