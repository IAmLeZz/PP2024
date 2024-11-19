#include <stdio.h>
//
// Created by Álvaro on 11/9/2024.
//
long otra(int n)
{
    long rta;
    if( n == 0)
        rta = 0;
    else
        rta = n+otra(n-1);
    return(rta);
}
int main(){
    long num = otra(4);
    printf("%d", num);

}