#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int x, y, w, h, list[4] = { 0 };
    scanf("%d %d %d %d", &x,&y,&w,&h);
    list[0] = x;
    list[1] = y;
    list[2] = abs(w - x);
    list[3] = abs(h - y);
    int min = list[0];
    for (int i = 0; i < 4; i++)
    {
        if (min > list[i])
            min = list[i];
    }
    printf("%d", min);
    
    return 0;
}
