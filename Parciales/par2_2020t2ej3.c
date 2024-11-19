//
// Created by Álvaro on 11/10/2024.
//
#include <stdio.h>
#define MAX 25

int decToBin(int num) {
if (num == 0)
        return 0;
    else
        return (num % 2 + 10 *
                decToBin(num / 2));
}

int binToDec(int num, int pos) {
    int res = 0;
    if (num == 0) {
        res = 0;
    } else {
        if (num == 1) {
            res = 1;
        } else {
            res = (num%10)+binToDec(num/10, pos+1)*2;
        }
    }
    return res;
}

int main() {
    decToBin(23);
    int num = binToDec(10111, 0);
    printf("%d", num);
}