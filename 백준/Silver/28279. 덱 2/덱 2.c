#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int c = 0;
typedef struct node
{
	int n;
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
void m1(deq* d, int value)
{
	c++;
	node* new = (node*)malloc(sizeof(node));
	new->n = value;
	new->prev = NULL;
	new->next = d->front;
	if (d->front == NULL)
		d->rear = new;
	else
	{
		d->front->prev = new;
	}
	d->front = new;

}
void m2(deq* d, int value)
{
	c++;
	node *new = (node*)malloc(sizeof(node));
	new->n = value;
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
void m3(deq* d)
{
	
	if (d->front == NULL)
	{
		printf("-1\n");
		return;
	}
	else
	{
		c--;
		int n = d->front->n;
		printf("%d\n", n);
		d->front = d->front->next;
		if (d->front == NULL)
			d->rear = NULL;
		else
		{
			d->front->prev = NULL;
		}
	}
}
void m4(deq* d)
{
	
	if (d->rear == NULL)
	{
		printf("-1\n");
		return;
	}
	else
	{
		c--;
		int n = d->rear->n;
		printf("%d\n", n);
		d->rear = d->rear->prev;
		if (d->rear == NULL)
			d->front = NULL;
		else
			d->rear->next = NULL;
	}
}
void m5()
{
	printf("%d\n", c);
}
void m6()
{
	if (c == 0)
		printf("1\n");
	else
		printf("0\n");
}
void m7(deq* d)
{
	if (c == 0)
	{
		printf("-1\n");
		return;
	}
	else
	{
		int n = d->front->n;
		printf("%d\n", n);
	}
}
void m8(deq* d)
{
	if (c == 0)
	{
		printf("-1\n");
		return;
	}
	else
	{
		int n = d->rear->n;
		printf("%d\n", n);
	}
}
int main(void)
{
	deq* d = newdeq();
	int how = 0,t;
	scanf("%d", &how);
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			int a;
			scanf("%d", &a);
			m1(d, a);
		}
		else if (t == 2)
		{
			int a;
			scanf("%d", &a);
			m2(d, a);
		}
		else if (t == 3)
		{
			m3(d);
		}
		else if (t == 4)
		{
			m4(d);
		}
		else if (t == 5)
		{
			m5();
		}
		else if (t == 6)
		{
			m6();
		}
		else if (t == 7)
		{
			m7(d);
		}
		else
			m8(d);
	}
	return 0;
}

