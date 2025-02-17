#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct node
{
	char s;
	struct  node* next;
	
	
}node;
int delete(node** top)
{

	
	node* now = *top;
	
	*top = now->next;
	free(now);
	return 1;

}
void put(node** top,char s)
{
	
	
	node* new = (node*)malloc(sizeof(node));
	new->s = s;
	new->next = *top;
	*top = new;
}

int main(void)
{
	
	
	char s[101]=" ";
	
	while (1)
	{

		node* stack = NULL;
		fgets(s, 102, stdin);
		if (s[0]=='.')
			break;
		int len = strlen(s);
		int c = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']')
			{
				
				continue;
			}
			else
			{
				if (stack != NULL)
				{
					//printf("stack is %c and s[i] is %c and c is %d\n", stack->s, s[i], c);
					if (stack->s == '(' && s[i] == ')')
						c-=delete(&stack);
					else if (stack->s == '[' && s[i] == ']')
						c-=delete(&stack);
					else
					{
						put(&stack, s[i]);
						c++;
						//printf("put %c and c is %d\n", s[i], c);
					}
					
				}
				else
				{
					put(&stack, s[i]);
					c++;
					//printf("put %c and c is %d\n", s[i], c);
				}
				
			}
			
		}
		if (c != 0)
		{
			printf("no\n");
			
		}
		else 
		{
			printf("yes\n");
			
		}
		
		
		

	}
	
	
	return 0;
}

