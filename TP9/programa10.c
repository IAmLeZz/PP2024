//
// Created by Álvaro on 11/6/2024.
//
#include <stdio.h>

void cosa( char cad[], int i) {
    if( cad[i] != '\0' )
    {
        cosa(cad,i+1);
        printf("%c", cad[i] );
    }
}

int main() {
    char text[30] = "Hola que tal";
    int i = 0;
    cosa(text, i);

}