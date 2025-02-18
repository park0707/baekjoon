#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct node
{
	int n;
	struct  node* next;
}node;
typedef struct que
{
	node* front;
	node* rear;
}que;
que* newque()
{
	que* new = (que*)malloc(sizeof(que));
	new->front = NULL;
	new->rear = NULL;
	return new;
}
void push(que* que,int value)
{
	
	node* new = (node*)malloc(sizeof(node));
	new->n = value;
	new->next = NULL;
	if (que->rear == NULL)
	{
		que->front = new;
		que->rear = new;
		return;
	}
	que->rear->next = new;
	que->rear = new;
}
 void pop(que* que,node *no)
{
	 if (que->front == NULL)
	 {
		 
		 return 0;
	 }
	node* tmp = que->front;
	que->front = no;
	
	que->front = que->front->next;
	if (que->front == NULL)
		que->rear = NULL;
	que->front = tmp;
	free(tmp);
	
}


int main(void)
{
	que* q = newque();
	int how,t,c=0;
	
	scanf("%d %d", &how,&t);
	for (int i = 1; i <= how; i++)
	{
		push(q, i);
	}
	if (t == 1)
	{
		how--;
		printf("<");
		node* now = q->front;
		while (how--)
		{
			printf("%d, ", now->n);
			now = now->next;
		}
		printf("%d>", now->n);
		return 0;
	}
	node* now = q->front;
	node* be = NULL;
	printf("<");
	while (1)
	{
		if (c == how-1)
			break;
		for (int i = 0; i < t-1; i++)
		{
			
			be = now;
			
			if (now->next == NULL)
			{
				now = q->front;
				continue;
			}
			now = now->next;
			//printf("now is %d\n", now->n);
		}
		c++;
		//printf("now's n is %d and be's n is %d\n", now->n, be->n);
		printf("%d, ", now->n);
		if (now->next == NULL)
		{
			be->next = NULL;
			now = q->front;
		}
		else
		{
			be->next = now->next;
			now = be->next;
		}
	}
	printf("%d>", now->n);
	return 0;
}

