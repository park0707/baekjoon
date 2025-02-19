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

void push(deq* d, int n,int data)
{
	
	node *new = (node*)malloc(sizeof(node));
	new->n = n;
	new->data = data;
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
void move(deq* d, node** n,int move)
{
	if (move > 0)
	{
		for (int i = 0; i < move-1; i++)
		{
			//printf("in plus move method now is %d\n", (*n)->n);
			if ((*n)->next == NULL)
				(*n) = d->front;
			else
			{
				(*n) = (*n)->next;
			}
			

		}
	}
	else
	{
		for (int i = 0; i < abs(move); i++)
		{
			//printf("in minus move method now is %d\n", (*n)->n);
			if ((*n)->prev == NULL)
				(*n) = d->rear;
			else
			{
				(*n) = (*n)->prev;
			}
				
		}
	}
}
void debug(deq* d,int how)
{
	printf("debugh start \n");
	node* now = d->front;
	for (int i = 0; i < how; i++)
	{
		printf("now id %d ", now->n);
		now = now->next;
	}
	printf("\n debug end ");
}
int main(void)
{
	deq* d = newdeq();
	int how = 0,t;
	scanf("%d", &how);
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &t);
		push(d, i + 1, t);
		
	}
	int n = d->front->data;
	printf("%d ",d->front->n );
	d->front = d->front->next;
	if (d->front == NULL)
		return 0;
	else
		d->front->prev = NULL;
	how--;
	node* now = d->front;
	while (1)
	{
		if (how == 0)
			break;
		//printf("data is %d\n", n);
		move(d, &now, n);
		//printf("now is %d\n", now->n);
		printf("%d ", now->n);
		n = now->data;
		if (now->next == NULL)
		{
			if (now->prev == NULL)
				return 0;
			node* tmp = now;
			tmp->prev->next = NULL;
			d->rear = now->prev;
			now = d->front;
			free(tmp);
			
		}
		else if (now->prev == NULL)
		{
			node* tmp = now;
			tmp->next->prev = NULL;
			now = tmp->next;
			d->front = now;
			free(tmp);
		}
		else
		{
			node* tmp = now;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			now = tmp->next;
			free(tmp);

		}
		how--;
		//debug(d, how);
	}
	return 0;
}

