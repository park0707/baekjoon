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
	return 2;

}
void put(node** top,char s)
{
	
	
	node* new = (node*)malloc(sizeof(node));
	new->s = s;
	new->next = *top;
	*top = new;
}
//아이디어, 첫 문자를 스택에 넣고 이후 문자를 올바른 괄호인지 비교, 올바르면 최근 문자를 스택에서 제거하고 현재 문자를 뛰어넘음, 올바르지 않으면 삽입
//최종적으로 스택에 어떤 문자도 저장되어 있지 않다면 yes출력 아니면 no 출력
int main(void)
{
	
	long long how;
	char s[50];
	scanf("%lld", &how);
	for (long long i = 0; i < how; i++)
	{
		node* stack = NULL;
		scanf("%s", s);
		int len = strlen(s);
		int c = 0;
		put(&stack, s[0]);
		for (int j = 1; j < len; j++)
		{
			
			if (stack != NULL && stack->s == '(' && s[j] == ')')
			{
				
				c += delete(&stack);
			}
			else
			{
				put(&stack, s[j]);
			}
			
		}
		if (len == c)
			printf("YES\n");
		else
			printf("NO\n");
		
		
	}
	
	
	return 0;
}

