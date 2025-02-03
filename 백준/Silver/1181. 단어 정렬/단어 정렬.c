#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
typedef struct {
    char str[51];
}string;
int compare(const void* a, const void* b)
{
    string* s1 = (string*)a;
    string* s2 = (string*)b;

    if (strlen(s1->str) != strlen(s2->str))
    {
        return strlen(s1->str) - strlen(s2->str);
    }
    else
    {
        return strcmp(s1->str, s2->str);
    }

}
int main(void)
{
    int n;
    
    scanf("%d", &n);
    string strs[20000];
    for (int i = 0; i < n; i++)
    {
        
        scanf("%s", strs[i].str);
        
       
    } 
    qsort(strs, n, sizeof(string), compare);
    
    printf("%s\n", strs[0].str);
    for (int i = 1; i < n; i++)
    {
        if (strcmp(strs[i].str, strs[i - 1].str) == 0)
            continue;
        else
        {
            printf("%s\n", strs[i].str);
        }
    }
        
    
    return 0;
}

