#include <stdio.h>
#define MAX 100

int copiarElementos(int *arr, int *arr2, int n) {
    int *p = arr;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if (*(p+i)>100) {
            *arr2 = *(p+i);
            arr2++;
            count++;
        }
    }
    return count;
}

int main() {
    int arr[25] = {12, 5, 352, 101, 102, 9, 201, 100, 9821};
    int arr2[25];
    int n = 9;

    int elems = copiarElementos(arr, arr2, n);

    for(int i = 0; i < elems; i++) {
        printf("%d \n", arr2[i]);
    }
}