#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int main(void)
{   
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    for (int i = -999; i <= 999; i++)
    {
        for (int j = -999; j <= 999; j++)
        {
            if (a * i + b * j == c && d*i+e*j == f)
            {
                printf("%d %d", i, j);
            }
        }
    }
    
    return 0;
}
