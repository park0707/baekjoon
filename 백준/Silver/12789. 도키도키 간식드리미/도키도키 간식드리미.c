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
void delete(node** top)
{

	
	node* now = *top;
	
	*top = now->next;
	free(now);
	

}
void put(node** top,int n)
{
	
	
	node* new = (node*)malloc(sizeof(node));
	new->n = n;
	new->next = *top;
	*top = new;
}
void check(node** top, int *c)
{
	if (*top == NULL)
		return;
	node* now = *top;
	if (now->n == *c)
	{
		delete(top);
		(*c)++;
		check(top, c);
	}
}
// 입력 받는 숫자가 목표 값이 아니면 스택에 저장하고 맞으면 통과하고 스택에 있는 값들이 그다음 갑에 해당하는 지 검사
int main(void)
{
	int how, n,c=1;
	scanf("%d", &how);
	node* stack=NULL;
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &n);
		//printf("n is %d and c is %d \n", n,c);
		if (n == c)
		{
			c++;
			check(&stack, &c);
			
			continue;
		}
		else
		{
			if (stack != NULL)
			{
				//printf("stack is %d and n is %d and c is %d\n", stack->n, n,c);
				if (stack->n < n)
					break;
				else if (stack->n == c)
				{
					check(&stack, &c);
				}
				else
					put(&stack, n);
			}
			else
				put(&stack, n);
		}
		

	}
	
	if (stack == NULL)
		printf("Nice\n");
	else
		printf("Sad\n");
	
	
	
	
	return 0;
}

