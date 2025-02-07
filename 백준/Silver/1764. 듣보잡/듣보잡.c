#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
typedef struct node
{
    char* name;
    int stance;
    struct node *next;
}node;
typedef struct hash
{
    node** bucket;
    int size;
}hash;
int hashfunc(char *key,hash *map)
{
    int hashn=0;
    while (*key)
    {
        hashn = (hashn * 31 + *key++) % map->size;
    }
    return hashn;


}
node* newnode(char *key, int value)
{
    node* new = (node*)malloc(sizeof(node));
    new->name = strdup(key);
    new->stance = value;
    new->next = NULL;
    return new;
}
hash* newhash(int size)
{
    hash *map = (hash*)malloc(sizeof(hash));
    map->bucket = (node**)calloc(size,sizeof(node*));
    map->size = size;
    return map;
}
void hashput(char *key, int value, hash *map)
{
    int i = hashfunc(key, map);
    node* current = map->bucket[i];
    while (current)
    {
        if (strcmp(current->name,key)==0)
        {
            
            current->stance = value;
            return;
        }
        else
            current = current->next;
    }

    node *new = newnode(key, value);
    new->next = map->bucket[i];
    map->bucket[i] = new;
}
int hashget(char *key, hash *map)
{
    int i = hashfunc(key, map);
    node* current = map->bucket[i];
    while (current)
    {
        if (strcmp(current->name,key)==0)
        {
            return current->stance;
        }
        else
            current = current->next;
    }
    return 0;
}
void freehash(hash *map)
{
    for (int i = 0; i < map->size; i++)
    {
        node* current = map->bucket[i];
        while (current)
        {
            node* tmp = current;
            free(tmp->name);
            free(tmp);
            current = current->next;
        }
    }
    free(map->bucket);
    free(map);
}
int compare(const void* a, const void* b)
{

    return strcmp(*(char**)a, *(char**)b);
}
int main(void)
{
    int n, m,c=0;
    char tmp[21];
    scanf("%d %d", &n,&m);
    hash* map = newhash(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        hashput(tmp, 1, map);
    }
    
    char ** arr = (char**)malloc(m * sizeof(char*));
    char** result = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) 
    {
        arr[i] = (char*)malloc(21 * sizeof(char));
    }
    for (int i = 0; i < m; i++)
    {
        result[i] = (char*)malloc(21 * sizeof(char));
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (hashget(arr[i], map) != 0)
        {
            strcpy(result[c], arr[i]);
            c++;
            
        }

    }
    printf("%d\n", c);
    qsort(result, c, sizeof(char*), compare);
    for (int i = 0; i < c; i++)
    {
        printf("%s\n", result[i]);
    }
    for (int i = 0; i < m; i++) 
    {
        free(arr[i]); 
    }
    for (int i = 0; i < m; i++)
    {
        free(result[i]);
    }
    freehash(map);
    free(arr);
    free(result);
    return 0;
}

