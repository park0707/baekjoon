#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int a, b, c,i=0;
    int* arr = malloc(1 * sizeof(int));
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("%d", a + b + c);
    }
    else
    {
        while (1)
        {
            if (!(a + b > c))
                c--;
            else if (!(a + c > b))
                b--;
            else if (!(b + c > a))
                a--;
            else
                break;
        }
        printf("%d", a + b + c);
    }
    return 0;
}
