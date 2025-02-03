#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int main(void) {
    int n;
    scanf("%d", &n);

    
    int count[100001] = {0};

    
    for (int i = 0; i < n; i++) 
    {
        int num;
        scanf("%d", &num);
        count[num]++;
    }

    
    for (int i = 1; i <= 10000; i++) 
    {
        while (count[i] > 0) 
        {
            printf("%d\n", i);
            count[i]--;
        }
    }

    return 0;
}
