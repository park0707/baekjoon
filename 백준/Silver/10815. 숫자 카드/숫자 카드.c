#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int search(int find, int arr[],int how)
{
    int low = 0, high = how - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == find)
            return 1;
        else if (arr[mid] < find)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}
int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int main(void)
{
    int card, find;
    scanf("%d", &card);
    int* cardarr = malloc(card * sizeof(int));
    
    for (int i = 0; i < card; i++)
    {
        scanf("%d", &cardarr[i]);
        
    }
    
    scanf("%d", &find);
    int* findarr = malloc(find * sizeof(int));
    for (int i = 0; i < find; i++)
    {
        scanf("%d", &findarr[i]);
    }
    qsort(cardarr, card, sizeof(int), compare);
    for (int i = 0; i < find; i++)
    {
        printf("%d ", search(findarr[i], cardarr, card));
    }



    free(cardarr);
    free(findarr);
    return 0;
}

