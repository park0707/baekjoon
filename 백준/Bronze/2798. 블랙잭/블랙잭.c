#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int main(void)
{   
    int how, num,max=0;
    scanf("%d %d", &how, &num);
    int *card = malloc(how * sizeof(int));
    for (int i = 0; i < how; i++)
    {
        scanf("%d", &card[i]);
    }
    for (int i = 0; i < how; i++)
    {
        int temp = 0;
        for (int j = 1; j < how  - i; j++)
        {
            
            if (card[j-1] < card[j])
            {
                temp = card[j];
                card[j] = card[j - 1];
                card[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < how-2; i++)
    {
        for (int j = i + 1; j < how ; j++)
        {
            for (int k = j+1; k < how ; k++)
            {
                int n = card[i] + card[j] + card[k];
                if (n <= num)
                {
                    if (max < n)
                        max = n;
                    
                }
            }
        }
    }
    printf("%d", max);

   
    return 0;
}
