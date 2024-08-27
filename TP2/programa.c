#include <stdio.h>
#include <conio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    char op = getch();  // Lee un solo carácter (el operador)

    // Uso de if-else para realizar la operación correspondiente
    if (op == '+') {
        printf("%d", a + b);
    } else if (op == '-') {
        printf("%d", a - b);
    } else if (op == '*') {
        printf("%d", a * b);
    } else if (op == '/') {
        if (b != 0) {
            printf("%d", a / b);
        } else {
            printf("error");
        }
    } else {
        printf("opción no válida");
    }

    return 0;
}