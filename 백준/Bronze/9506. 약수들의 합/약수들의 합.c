#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void perfectcheck(int n)
{
    int* arr = calloc(n , sizeof(int));
    int c = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (n % (i + 1) == 0)
        {
            arr[c] = (i + 1);
            c++;
        }
    }
    printf("%d = %d ", n,arr[0]);
    for (int i = 1; i < c; i++)
    {
        printf("+ %d ", arr[i]);
    }
    printf("\n");

}
int main(void)
{   
    int *arr = malloc(1 * sizeof(int));
    int *arr2 = malloc(1 * sizeof(int));
    int c = 0,num=0;
    while (1)
    {

        scanf("%d", &num);
        if (num == -1)
            break;
        int n1 = 0;
        arr = realloc(arr, (c + 1) * sizeof(int));
        arr2 = realloc(arr2, (c + 1) * sizeof(int));
        arr[c] = num;
        
        for (int i = 0; i < num - 1; i++)
        {
            if (num % (i + 1) == 0)
            {
                
                n1 += (i + 1);
            }
        }
        if (n1 == num)
        {
            
            arr2[c] = 1;
            c++;
        }
        else
        {
            
            arr2[c] = 0;
            c++;
        }
        
    }
    for (int i = 0; i < c; i++)
    {
        if (arr2[i] == 1)
        {
            perfectcheck(arr[i]);
        }
        else
        {
            printf("%d is NOT perfect.\n", arr[i]);
        }
    }
    

    free(arr);
    free(arr2);
    return 0;
}
