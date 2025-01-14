#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int *arr = malloc(1 * sizeof(int));
    int c = 0,num,index;
    scanf("%d %d", &num, &index);
    for (int i = 0; i < num; i++)
    {
        arr = realloc(arr, (c + 1) * sizeof(int));
        if (num % (i + 1) == 0)
        {
            
            arr[c] = (i + 1);
            
            c++;
        }

    }
    if (c < index)
    {
        printf("0");
    }
    else
    {
        for (int i = 0; i < c - 1; i++) {
            int temp;
            for (int j = 0; j < c - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }


        printf("%d", arr[index - 1]);
    }
    
  
    return 0;
}
