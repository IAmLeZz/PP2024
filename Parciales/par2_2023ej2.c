#include <stdio.h>
#define MAX 100

int devolverPos(int *arr, int n, int k) {
    int *p = arr;

    for(int i = 0; i < n; i++) {
        if (*p == k) {
            return i;
        }
        p++;
    }
    return -1;
}

int main() {
    int arr[MAX] = {13, 32, 12, 54};
    int pos = devolverPos(arr, 4, 12);
    printf("%d", pos);
}