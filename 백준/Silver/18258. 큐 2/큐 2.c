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
	c++;
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
 void pop(que* que)
{
	 if (c > 0)
		 c--;
	 if (que->front == NULL)
	 {
		 printf("-1\n");
		 return;
	 }
	node* now = que->front;
	int n = now->n;
	que->front = que->front->next;
	if (que->front == NULL)
		que->rear = NULL;
	free(now);
	printf("%d\n", n);
}
void size(que* que)
{
	
	printf("%d\n", c);
}
void empty(que* que)
{
	if (que->front == NULL)
		printf("1\n");
	else
		printf("0\n");
}
void fro(que* que)
{
	if (que->front == NULL)
		printf("-1\n");
	else
	{
		printf("%d\n", que->front->n);
	}
}
void back(que* que)
{
	if (que->front == NULL)
		printf("-1\n");
	else
		printf("%d\n", que->rear->n);
}

int main(void)
{
	que* q = newque();
	int how;
	scanf("%d", &how);
	int n;
	char s[7];
	for (int i = 0; i < how; i++)
	{
		scanf("%s", s);
		if (strcmp(s, "push") == 0)
		{
			scanf("%d", &n);
			push(q, n);
		}
		else if (strcmp(s, "pop") == 0)
			pop(q);
		else if (strcmp(s, "size") == 0)
			size(q);
		else if (strcmp(s, "empty") == 0)
			empty(q);
		else if (strcmp(s, "front") == 0)
			fro(q);
		else
			back(q);

	}
	
	return 0;
}

