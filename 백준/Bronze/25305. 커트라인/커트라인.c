#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int main(void)
{  
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int* arr = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n1 - 1; i++)
    {
        for (int j = 0; j < n1 - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    printf("%d", arr[n2 - 1]);
    return 0;
}

