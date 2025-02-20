
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct node
{
	int n;
	int data;
	struct  node* next;
	struct node* prev;
}node;
typedef struct deq
{
	node* front;
	node* rear;
}deq;
deq* newdeq()
{
	deq* new = (deq*)malloc(sizeof(deq));
	new->front = NULL;
	new->rear = NULL;
	return new;
}

void push(deq* d, int n)
{

	node* new = (node*)malloc(sizeof(node));
	new->n = n;
	new->prev = d->rear;
	new->next = NULL;
	if (d->rear == NULL)
		d->front = new;
	else
	{
		d->rear->next = new;
	}
	d->rear = new;
}


int main(void)
{
	deq* d = newdeq();
	int how = 0, t,c=0;
	scanf("%d", &how);
	int* arr = malloc(how * sizeof(int));
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &t);
		
		if (t == 0)
		{
			push(d, t);
			arr[c] = i;
			c++;
		}

	}
	//printf("arr is %d %d\n", arr[0], arr[1]);
	c = 0;
	node* now = d->front;
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &t);
		if (arr[c] == i)
		{
			if (now == NULL)
				continue;
			//printf("%d is save\n", t);
			now->data = t;
			now = now->next;
			c++;
		}
	}
	scanf("%d", &how);
	int* arr2 = malloc(how * sizeof(int));
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &arr2[i]);
		
	}
	if (how < c && d->front != NULL)
	{
		node* now = d->rear;
		for (int i = 0; i < how-1; i++)
		{
			
			printf("%d ", now->data);
			now = now->prev;
		}
		printf("%d ", now->data);
	}
	else if(how >= c && d->front != NULL)
	{
		node* now = d->rear;
		for (int i = 0; i < c-1; i++)
		{
			
			printf("%d ", now->data);
			now = now->prev;
		}
		printf("%d ", now->data);
		for (int i = 0; i < how - c; i++)
		{
			printf("%d ", arr2[i]);
		}
	}
	else
	{
		for (int i = 0; i < how; i++)
		{
			printf("%d ", arr2[i]);
		}
	}
	free(arr);
	free(arr2);
	return 0;
}