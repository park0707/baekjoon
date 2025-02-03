#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
typedef struct {
    int x;
    int y;

}point;
int compare(const void* a, const void* b)
{
    point *p1 = (point*)a;
    point *p2 = (point*)b;
    if (p1->x != p2->x)
    {
        return p1->x - p2->x;
    }
    else
    {
        return p1->y - p2->y;
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    point* arr = (point*)malloc(n * sizeof(point));
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, n, sizeof(point), compare);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    free(arr);
    return 0;
}

