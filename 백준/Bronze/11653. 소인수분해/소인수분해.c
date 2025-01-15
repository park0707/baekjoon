#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int num,n=2,c=0;
    int *arr = malloc(1 * sizeof(int));
    scanf("%d", &num);
    if (num == 1)
    {
        printf(" ");
        return 0;
    }
    while (1)
    {
        if (num == n )
        {
            
            arr = realloc(arr, (1 + c) * sizeof(int));
            arr[c] = n;
            break;

        }
        if (num % n == 0)
        {
            arr = realloc(arr, (1 + c) * sizeof(int));
            arr[c] = n;
            c++;
            num = num/n;
            
        }
        else
            n++;
       


    }
    for (int i = 0; i <= c; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
 
    
    
    
    return 0;
}
