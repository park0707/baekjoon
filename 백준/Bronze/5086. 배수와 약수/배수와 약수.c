#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    char* arr = malloc(1 * sizeof(char));
    int i = 0;
    while (1)
    {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        if (n1 == 0 && n2 == 0)
            break;
        else if (n1 == n2)
            break;
        arr = realloc(arr, (1 + i) * sizeof(char));
        
        if (n1 == 0 || n2 == 0)
        {
            arr[i] = '3';

            i++;
            continue;
        }
        else if (n2 % n1 == 0)
        {
            
            arr[i] = '1';
            
            i++;
        }
        else if (n1 % n2 == 0)
        {
            
            arr[i] = '2';
            
            i++;
        }
        
        else
        {
            
            arr[i] = '3';   
            
            i++;
        }
    }
    for (int j = 0; j < i; j++)
    {
        if (arr[j] == '1')
            printf("factor\n");
        else if(arr[j] == '2')
            printf("multiple\n");
        else
            printf("neither\n");
    }
  
    return 0;
}
