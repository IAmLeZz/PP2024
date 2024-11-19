#include <stdio.h>
#define MAX 100

void invertirString(char *s) {
    if (*s != '\0') {
        invertirString((s+1));
        printf("%c", *s);
    }
}

int main() {
    char *string = "Hola";
    invertirString(string);

}
