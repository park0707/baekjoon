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
 int pop(que* que)
{
	 if (que->front == NULL)
	 {
		 
		 return 0;
	 }
	node* now = que->front;
	int n = now->n;
	que->front = que->front->next;
	if (que->front == NULL)
		que->rear = NULL;
	free(now);
	return n;
}


int main(void)
{
	que* q = newque();
	int how,t=0;
	scanf("%d", &how);
	for (int i = 1; i <= how; i++)
	{
		push(q, i);
	}
	for (int i = 1; i <2* how-1; i++)
	{
		if (t == 0)
		{
			int n = pop(q);
			t = 1;
			//printf("%d is delete \n", n);
		}
		else
		{
			t = 0;
			int n = pop(q);
			//printf("%d is move to end \n", n);
			if (n != 0)
				push(q, n);
			//printf("%d is last value \n", q->rear->n);
		}
	}
	printf("%d", q->rear->n);
	return 0;
}

