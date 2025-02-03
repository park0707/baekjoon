#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int main(void)
{  
    int sum=0,ave,mid;
    
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        
        for (int j = 0; j <4 - i; j++)
        {
            
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    ave = sum / 5;
    mid = arr[2];
    printf("%d\n%d", ave, mid);
    return 0;
}

