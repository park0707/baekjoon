#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
typedef struct node
{
    long long key;
    long long stance;
    struct node *next;
}node;
typedef struct hash
{
    node** bucket;
    int size;
}hash;
long long hashfunc(long long key,hash *map)
{
    return (key * 31) % map->size;


}
node* newnode(long long key, long long value)
{
    node* new = (node*)malloc(sizeof(node));
    new->key = (key);
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
void hashput(long long key, long long value, hash *map)
{
    long long i = hashfunc(key, map);
    node* current = map->bucket[i];
    while (current)
    {
        if (current->key == key)
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
int hashget(long long key, hash *map)
{
    long long i = hashfunc(key, map);
    node* current = map->bucket[i];
    while (current)
    {
        if (current->key == key)
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
            current = current->next;
            free(tmp);
        }
    }
    free(map->bucket);
    free(map);
}
int main(void)
{
    int n, m,c=0;
    long long tmp;
    scanf("%d %d", &n,&m);
    hash* map = newhash(n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        hashput(tmp, tmp, map);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &tmp);
        if (hashget(tmp, map) != 0)
        {
            c++;
        }
    }
    printf("%d", n + m - (c * 2));
    
  
    
    freehash(map);
   
    return 0;
}

