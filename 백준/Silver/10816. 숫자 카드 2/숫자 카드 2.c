#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
typedef struct node
{
    int n;
    int how;
    struct node *next;
}node;
typedef struct hash
{
    node** bucket;
    int size;
}hash;
int hashfunc(int key,hash *map)
{
    return ((key + 10000000)*31) % map->size;

}
node* newnode(int key, int value)
{
    node* new = (node*)malloc(sizeof(node));
    new->n = (key);
    new->how = (value);
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
void hashput(int key, int value, hash *map)
{
    int i = hashfunc(key, map);
    node* current = map->bucket[i];
    while (current)
    {
        if (current->n == key)
        {
            
            current->how = value;
            return;
        }
        else
            current = current->next;
    }

    node *new = newnode(key, value);
    new->next = map->bucket[i];
    map->bucket[i] = new;
}
int hashget(int key, hash *map)
{
    int i = hashfunc(key, map);
    node* current = map->bucket[i];
    while (current)
    {
        if (current->n == key)
        {
            return current->how;
        }
        else
            current = current->next;
    }
    return 0;
}
void freehash(hash *map)
{
    
    free(map->bucket);
    free(map);
}
int main(void)
{
    int n, m,tmp;
    scanf("%d", &n);
    hash* map = newhash(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (hashget(tmp, map) == 0)
        {
            hashput(tmp, 1, map);
        }
        else
        {
            hashput(tmp, hashget(tmp, map) + 1, map);
        }
    }
    scanf("%d", &m);
    int* arr = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ", hashget(arr[i], map));
    }
    freehash(map);
    free(arr);
    return 0;
}

