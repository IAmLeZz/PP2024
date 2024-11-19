//
// Created by Álvaro on 11/14/2024.
//
#include <stdio.h>
#define MAX 100

void multiplicarArrays(const int *arr1, const int *arr2, int *arr3) {
    for (int i = 0; i < 5; i++) {
        *arr3 = *arr1 * *arr2;
        arr1++;
        arr2++;
        arr3++;
    }
}

int main() {
    int arr1[MAX] = {2, 3, 5, 6, 7};
    int arr2[MAX] = {2, 12, 7, 9, 15};
    int arr3[MAX];
    multiplicarArrays(arr1, arr2, arr3);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr3[i]);
    }
}