#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int check(int n)
{
    if (n == 1)
        return 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (n % (i + 1) == 0)
            return 0;

    }
    return 1;
}
int main(void)
{   
    int start,end,total=0,min=0;
    scanf("%d", &start);
    scanf("%d", &end);
    
    for (int i = start; i <= end; i++)
    {
        if (check(i) == 1)
        {
            total += i;
            if (min == 0)
                min = i;
            else
            {
                if (min > i)
                    min = i;
            }
        }
    }
    if (total == 0)
        printf("-1");
    else
    {
        printf("%d\n%d", total, min);
    }
    
    
    
    return 0;
}
