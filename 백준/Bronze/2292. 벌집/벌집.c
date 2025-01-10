#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int how,check=1,n=1;
    scanf("%d", &how);
    if (how == 1)
    {
        printf("1");
    }
    else
    {
        while (1)
        {
            check += 6 * n;
            if (how <= check)
            {
                printf("%d", n + 1);
                break;
            }
            else
                n++;
        }
    }
    
    return 0;
}
