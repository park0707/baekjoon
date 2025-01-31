#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int value(int kg, int how)
{
    return kg - 5 * how;
}
int main(void)
{  
    int kg, count = 0, max = 0;
    scanf("%d", &kg);
    max = kg / 5;
    int min = kg;
    for (int i = 0; i <= max; i++)
    {
        int temp = kg;
        temp = value(temp, i);
        
        if (temp % 3 == 0)
        {
            
            count = i + (temp / 3);
            if (min > count)
                min = count;

        }
    }
    if (min == kg)
        printf("-1");
    else
        printf("%d", min);
        
    return 0;
}

