#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int x, y, list[3][2] = {0};
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &list[i][0], &list[i][1]);
    }
    if (list[0][0] != list[1][0] && list[0][0] != list[2][0])
        x = list[0][0];
    else if (list[1][0] != list[0][0] && list[1][0] != list[2][0])
        x = list[1][0];
    else
        x = list[2][0];
    if (list[0][1] != list[1][1] && list[0][1] != list[2][1])
        y = list[0][1];
    else if (list[1][1] != list[0][1] && list[1][1] != list[2][1])
        y = list[1][1];
    else
        y = list[2][1];

    printf("%d %d",x,y );
    
    return 0;
}
