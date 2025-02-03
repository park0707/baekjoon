#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int compare(const void* a, const void* b) 
{
    return (*(int*)b - *(int*)a);
}
int main(void)
{
    int n,i=10,t=0;
    scanf("%d", &n);
    int arr[10];
    while (1)
    {
        if (n / 10 == 0)
        {
            arr[t] = n;
            t++;
            break;
        }
        else
        {
            
            arr[t] = n % 10;
            t++;
            n /= 10;
        }
        
    
    }
    
    qsort(arr, t, sizeof(int), compare);
    for (int i = 0; i < t; i++)
    {
        printf("%d", arr[i]);
    }
    
    return 0;
}

