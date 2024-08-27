#include <stdio.h>

int main() {
    int i;

    printf("Impares\t\tPares\n");

    for (i = 1; i <= 50; i += 2) {
        printf("%d\t\t%d\n", i, i + 1);
    }

    return 0;
}
