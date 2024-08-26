//
// Created by Álvaro on 8/26/2024.
//
#include <stdio.h>
#define m 6
void main() {
    int a,b,c;
    a = 5;
    b = 8;
    c = 2 * a - b;
    c = c - m;
    b = a + c - m;
    a = b * m;
    printf("%d",a);
    b = b -1;
    printf("%6d %6d",b,c);
}