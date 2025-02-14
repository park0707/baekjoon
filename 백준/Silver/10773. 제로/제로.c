#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
long long total = 0;
typedef struct node
{
	long long value;
	struct  node* next;
	
}node;
int delete(node** top)
{

	if (*top == NULL)
		return -1;
	node* now = *top;
	int r = now->value;
	*top = now->next;
	free(now);
	return r;

}
void put(node** top,long long value)
{
	total += value;
	if (value == 0)
	{
		total -= delete(top);
		return;
	}
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->next = *top;
	*top = new;
}
int main(void)
{
	node* stack = NULL;
	long long how,m;
	scanf("%lld", &how);
	for (int i = 0; i < how; i++)
	{
		scanf("%lld", &m);
		put(&stack, m);
	}
	printf("%lld", total);
	
	return 0;
}

