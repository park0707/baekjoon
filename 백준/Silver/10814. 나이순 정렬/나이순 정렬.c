#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
typedef struct {
    int age;
    char name[101];
    int index;
}people;
int compare(const void* a, const void* b) 
{
    people* p1 = (people*)a;
    people* p2 = (people*)b;

    if (p1->age != p2->age) 
    {
        return p1->age - p2->age; 
    }
    return p1->index - p2->index;
}
int main(void)
{
    int n,min=200,max=0,c=0;
    scanf("%d", &n);
    people* p = malloc(n * sizeof(people));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &p[i].age, p[i].name);
        p[i].index = i;
    }
    qsort(p, n, sizeof(people), compare);
    for (int i = 0; i < n; i++) 
    {
        printf("%d %s\n", p[i].age, p[i].name);
    }
    free(p);
    return 0;
}

