#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int compare(const void* a, const void* b)
{
    int n1 = *(int*)a;
    int n2 = *(int*)b;
    return n1 - n2;
}
int main(void)
{
    int n, c = 0;
    scanf("%d", &n);
    int* value = malloc(n * sizeof(int));
    int* only = calloc(n , sizeof(int));
    int* fin = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value[i]);
        fin[i] = value[i];
    }
    
    qsort(value, n, sizeof(int), compare);
    only[c++] = value[0];
    for (int i = 1; i < n; i++)
    {
        if (value[i] != value[i - 1])
        {
            only[c++] = value[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = c - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (fin[i] == only[mid])
            {
                printf("%d ", mid);
                break;
            }
            else if (fin[i] > only[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }


    free(value);
    free(only);
    free(fin);
    return 0;
}

