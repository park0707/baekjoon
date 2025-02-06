#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
typedef struct node
{
    char* name;
    char* status;
    struct node* next;
}node;
typedef struct hash
{
    node** bucket;
    int size;
}hash;
int hashfunc(char* key, int size)
{
    int ha = 0;
    while (*key)
    {
        ha = (ha * 31 + *key++) % size;
    }
    return ha;
}
node* newnode(char* key, char* value)
{
    node* new = malloc(sizeof(node));
    new->name = strdup(key);
    new->status = strdup(value);
    new->next = NULL;
    return new;
}
hash* newhash(int size)
{
    hash* new = malloc(sizeof(hash));
    new->bucket = (node**)calloc(size, sizeof(node*));
    new->size = size;
    return new;
}
void hashput(hash* map, char* key, char* value)
{
    int index = hashfunc(key, map->size);
    node* current = map->bucket[index];
    while (current)
    {
        if (strcmp(current->name, key) == 0)
        {
            free(current->status);
            current->status = strdup(value);
            return;
        }
        else
            current = current->next;
    }

    node* new = newnode(key, value);
    new->next = map->bucket[index];
    map->bucket[index] = new;
}
char* hashget(hash* map, char* key)
{
    int index = hashfunc(key, map->size);
    node* current = map->bucket[index];
    while (current)
    {
        if (strcmp(current->name, key) == 0)
        {
            return current->status;
        }
        else
            current = current->next;
    }
}
void freehash(hash* map)
{
    for (int i = 0; i < map->size; i++)
    {
        node* current = map->bucket[i];
        while (current)
        {
            node* tmp = current;
            current = current->next;
            free(tmp->name);
            free(tmp->status);
            free(tmp);
        }
    }
    free(map->bucket);
    free(map);
}
int compare(const void* a, const void* b)
{
    return strcmp(*(char**)b, *(char**)a);
}
int main(void)
{
    int n,c=0;
    char name[6], status[6];
    scanf("%d", &n);
    hash* hashmap = newhash(n);
    //char **arr = (char**)calloc(n , sizeof(char*));
    char **result = (char**)calloc(n , sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", name, status);
        hashput(hashmap,name, status);
        //arr[i] = strdup(name);
    }
    for (int i = 0; i < n; i++)
    {
        node* current = hashmap->bucket[i];
        while (current)
        {
            if (strcmp(hashget(hashmap, current->name), "enter") == 0)
            {
                result[c] = strdup(current->name);
                c++;
                current = current->next;
            }
            else
                current = current->next;
        }
    }
    qsort(result, c, sizeof(char*), compare);
    for (int i = 0; i < c; i++)
    {
        printf("%s\n", result[i]);
    }
    freehash(hashmap);
    for (int i = 0; i < c; i++)
    {
        free(result[i]);
    }
    

    //free(arr);
    free(result);
    return 0;
}

