#include  <stdio.h>
#include <stdlib.h>
int main()
{
    int x[5] = {2,4,6,8,10};
    int i;
    for(i=0;i < 5;i++)
    {
        printf("x[%d] = %d \n",i,x[i]);
        printf("&x[%d] = 0x%x \n",i,&x[i]);
    }
    return 0;
}