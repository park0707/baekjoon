#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct node
{
	char *key;
	int value;
	struct node* next;
}node;
typedef struct hash
{
	node** bucket;
	int size;
}hash;
hash* newhash(int size)
{
	hash* map = malloc(sizeof(hash));
	map->size = size;
	map->bucket = (node**)calloc(size, sizeof(node*));
	return map;
}
int hashfunc(char* key, int size)
{
	int hash = 0;
	while (*key)
	{
		hash = (hash * 31 + *key++)  % size;
	}
	return hash;
}
node* newnode(char* key, int value)
{
	node* new = malloc(sizeof(node));
	new->key = strdup(key);
	new->value = value;
	new->next = NULL;
	return new;
}
void push(hash* map, char* key, int value)
{
	int index = hashfunc(key, map->size);
	node* now = map->bucket[index];
	while (now)
	{
		if (strcmp(key, now->key) == 0)
		{
			now->value = value;
			return;
		}
		now = now->next;
	}

	node* new = newnode(key, value);
	new->next = map->bucket[index];
	map->bucket[index] = new;
 }
void delete(hash* map, char* key)
{
	int index = hashfunc(key, map->size);
	node* now = map->bucket[index];
	node* prev = NULL;
	while (now)
	{
		if (strcmp(now->key, key) == 0)
		{
			if (prev)
				prev->next = now->next;
			else
				map->bucket[index] = now->next;
			free(now->key);
			free(now);
			return;
		}
		prev = now;
		now = now->next;
		
	}
}
int search(hash* map, char* key)
{
	int index = hashfunc(key, map->size);
	node* now = map->bucket[index];
	while (now)
	{
		if (strcmp(key, now->key) == 0)
		{
			
			return now->value;
		}
		now = now->next;
	}
	return 0;
}
void freehash(hash* map)
{
	for (int i = 0; i < map->size; i++)
	{
		node* now = map->bucket[i];
		while (now)
		{
			node* tmp = now;
			now = now->next;
			free(tmp->key);
			free(tmp);
		}
	}
	free(map->bucket);
	free(map);
}
typedef struct
{
	char s[11];
	int value;
}str;
int compare(const void* a, const void* b)
{
	str* s1 = (str*)a;
	str* s2 = (str*)b;
	if (s1->value > s2->value)
		return -1;
	else if (s1->value < s2->value)
		return 1;
	else
	{
		if (strlen(s1->s) > strlen(s2->s))
			return -1;
		else if (strlen(s1->s) < strlen(s2->s))
			return 1;
		else
		{
			return strcmp(s1->s, s2->s);
		}
	}
}

int main(void)
{
	int how, stand;
	scanf("%d %d", &how, &stand);
	hash* map = newhash(how);
	int c = 0;
	char s[11];
	for (int i = 0; i < how; i++)
	{
		
		scanf("%s", s);
		if (strlen(s) >= stand)
		{
			if (search(map, s) == 0)
			{
				//printf("%s is save\n", s);
				push(map, s, 1);
				c++;
			}
			else 
			{
				push(map, s, search(map, s) + 1);
				//printf("%s 의 빈도는 %d\n", s, search(map, s));
			}
		}
		
	}
	int j = 0;
	str* sarr = calloc(c , sizeof(str));
	for (int i = 0; i < how; i++)
	{
		node* now = map->bucket[i];
		while (now)
		{
			if (now->key != NULL)
			{
				strcpy(sarr[j].s, now->key);
				sarr[j].value = now->value;
				now = now->next;
				j++;
			}
			
		}

	}
	
	qsort(sarr, j, sizeof(str), compare);
	for (int i = 0; i < j; i++)
	{
		printf("%s\n", sarr[i].s);
	}

    free(sarr);
	freehash(map);
	return 0;
}
