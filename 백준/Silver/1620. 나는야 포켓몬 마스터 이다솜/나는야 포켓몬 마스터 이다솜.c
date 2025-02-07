#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
typedef struct
{
    char name[21];
    int index;
}poketmon;
int compare1(const void* a, const void* b)
{
    poketmon* p1 = (poketmon*)a;
    poketmon* p2 = (poketmon*)b;
    return strcmp(p1->name, p2->name);
}
int check(char* s)
{
    
    
    while (*s)
    {
        if (!isdigit(*s))
            return 0;
        s++;
    }
    return 1;
}
void find1(poketmon arr[], char s[],int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (strcmp(s, arr[mid].name) == 0)
        {
            printf("%d\n", arr[mid].index);
            return;
        }
        else if (strcmp(s, arr[mid].name) < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
}
void find2(poketmon arr[], int s, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid].index == s)
        {
            printf("%s\n", arr[mid].name);
            return;
        }
        else if (s < arr[mid].index)
            high = mid - 1;
        else
            low = mid + 1;
    }
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    poketmon* arr1 = malloc(n * sizeof(poketmon));
    poketmon* arr2 = calloc(n , sizeof(poketmon));

    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr1[i].name);
        arr1[i].index = i+1;
        strcpy(arr2[i].name, arr1[i].name);
        arr2[i].index = arr1[i].index;
    }
    qsort(arr1, n, sizeof(poketmon), compare1);
    
    /*
    for (int i = 0; i < n; i++)
    {
        printf("arr1 is name = %s indes = %d and arr2 is name = %s index = %d\n", arr1[i].name, arr1[i].index, arr2[i].name, arr2[i].index);
    }
    */
    poketmon* question = malloc(m * sizeof(poketmon));
    for (int i = 0; i < m; i++)
    {
        scanf("%s", question[i].name);
    }
    for (int i = 0; i < m; i++)
    {
        
        if (check(question[i].name))
        {
            find2(arr2, atoi(question[i].name), n);
        }
        else
            find1(arr1, question[i].name, n);
    }
   
    free(arr1);
    free(arr2);
    return 0;
}

