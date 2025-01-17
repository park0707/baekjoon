#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int a, b, c,i=0;
    int* arr = malloc(1 * sizeof(int));
    while (1)
    {
        arr = realloc(arr, (1 + i) * sizeof(int));
        scanf("%d %d %d", &a,&b,&c);
        if (a == 0 && b == 0 && c == 0)
            break;
        int max = a;
        if (max < b)
        {
            if (b < c)
                max = c;
            else
                max = b;
        }
        else if (max < c)
        {
            max = c;
        }
        if (max >= a + b + c - max)
            arr[i] = 4;
        else
        {
            if (a == b && b == c)
                arr[i] = 1;
            else if (a == b || b == c || a == c)
                arr[i] = 2;
            else
                arr[i] = 3;

        }
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if(arr[j] == 1)
            printf("Equilateral\n");
        else if(arr[j] == 2)
            printf("Isosceles\n");
        else if(arr[j] == 3)
            printf("Scalene\n");
        else
            printf("Invalid\n");
    }
    
    
    
    
    
    return 0;
}
