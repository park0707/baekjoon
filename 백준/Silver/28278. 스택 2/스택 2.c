#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int total = 0;
typedef struct node
{
	int value;
	struct  node* next;
	
}node;
void m1(node** top,int value)
{
	total++;
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->next = *top;
	*top = new;
}
int m2(node** top)
{
	if (total > 0)
		total--;
	if (*top == NULL)
		return -1;
	node* now = *top;
	int r = now->value;
	*top = now->next;
	free(now);
	return r;

}
int m3(node* top)
{
	
	return total;
}
int m4(node* top)
{
	if (top == NULL)
		return 1;
	else
		return 0;

}
int m5(node* top)
{
	
	if (top == NULL)
		return -1;
	return top->value;
}

int main(void)
{
	node* stack = NULL;
	int how,m;
	scanf("%d", &how);
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &m);
		if (m == 1)
		{
			int v;
			scanf("%d", &v);
			m1(&stack, v);
		}
		else if (m == 2)
		{
			//printf("result = ");
			printf("%d\n", m2(&stack));
		}
		else if (m == 3)
		{
			//printf("result = ");
			printf("%d\n", m3(stack));
		}
		else if (m == 4)
		{
			//printf("result = ");
			printf("%d\n", m4(stack));
		}
		else
		{
			//printf("result = ");
			printf("%d\n", m5(stack));
		}
	}

	return 0;
}

