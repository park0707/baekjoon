#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int how, min_x , max_x, min_y, max_y, x, y;
    scanf("%d", &how);
    for (int i = 0; i < how; i++)
    {
        scanf("%d %d", &x, &y);
        if (i == 0)
        {
            min_x = x;
            min_y = y;
            max_x = x;
            max_y = y;
        }
        
        if (x > max_x)
            max_x = x;
        if (x < min_x)
            min_x = x;
        if (y > max_y)
            max_y = y;
        if (y < min_y)
            min_y = y;
    }
    printf("%d", (max_x - min_x) * (max_y - min_y));
    return 0;
}
