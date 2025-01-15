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
    int how,count=0;
    scanf("%d", &how);
    int* arr = malloc(how * sizeof(int));
    for (int i = 0; i < how; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < how; i++)
    {
        count += check(arr[i]);
    }
    printf("%d", count);
    
    free(arr);
    
    return 0;
}
