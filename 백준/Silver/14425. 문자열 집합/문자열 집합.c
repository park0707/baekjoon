#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int compare(const void* a, const void* b)
{
   
    return strcmp((const char*)a, (const char*)b);
}
int search(char find[], char list[][501],int how)
{
    int low = 0, high = how - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (strcmp(list[mid], find) == 0)
            return 1;
        else if (strcmp(list[mid], find) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}
int main(void)
{
    int n, m, count = 0;;
    scanf("%d %d", &n, &m);
    char (*arr)[501];
    arr = (char(*)[501])malloc(sizeof(char) * n * 501);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), compare);
    for (int i = 0; i < m; i++)
    {
        char s[501];
        scanf("%s", s);
        count += search(s, arr, n);
    }
    printf("%d", count);
    free(arr);

    return 0;
}

