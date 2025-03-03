
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
int dub(int n)
{
	int r = 1;
	for (int i = 0; i < n; i++)
	{
		r *= 3;
	}
	return r;
}
void method(int n,int *arr,int act)
{
	
	int total = dub(n);
	int r = total / dub(act);
	int c = 0,t = 0;
	//c가 제거하면 안되는 순간이고 t가 제거해야 되는 순간
	for (int i = 0; i < total; i++)
	{
		if (c < r)
		{
			t = 0;
			c++;
			continue;
		}
		else
		{
			
			if (t < r)
			{
				arr[i] = 1;
				t++;
				
			}
			if (t == r)
				c = 0;
		}
	}
	
	if (act == n)
	{
		for (int i = 0; i < dub(n); i++)
		{
			if (arr[i] == 0)
			{
				printf("-");

			}
			else
			{
				printf(" ");
			}
		}
		return;
	}
	method(n, arr, ++act);

}
int main(void)
{
	int how;
	while (scanf("%d", &how) != EOF)
	{
		if (how == 0)
		{
			printf("-\n");
			continue;
		}
		else
		{
			int* arr = calloc(dub(how), sizeof(int));
			method(how, arr,1);
			printf("\n");
			free(arr);
		}
	}
	
	return 0;
}
