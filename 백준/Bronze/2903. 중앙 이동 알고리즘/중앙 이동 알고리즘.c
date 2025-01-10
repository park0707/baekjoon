#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int repeat(int a,int b)
{
    int value = 1;
    for (int i = 0; i < b; i++)
    {
        value *= a;
    }
    return value;
}
int main(void)
{   
    int how;
    scanf("%d", &how);
    printf("%d", repeat(4,how)+repeat(2,how+1)+1);
    
    return 0;
}
