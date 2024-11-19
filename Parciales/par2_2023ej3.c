#include <stdio.h>
#define MAX 100

int invertirNum(int num, int rev) {
    if (num == 0){
      return rev;
    } else {
      return invertirNum(num/10, rev*10 + num%10);
    }
}

int main() {
    int numInv = invertirNum(546);
    printf("%d", numInv);
}