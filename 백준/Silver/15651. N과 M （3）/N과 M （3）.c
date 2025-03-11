
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
void printarr(int m, int* value)
{
	for (int i = 0; i < m; i++)
	{
		printf("%d ", value[i]);
	}
	printf("\n");
}


void find(int n, int m,int *arr,int *value,int index)
{
	
	if (index == m)
	{
		printarr(m, value);
	}
	else
	{
		int t;
		for (int i = 0; i < n; i++)
		{
			t = 0;
			/*
			for (int j = 0; j <= index; j++)
			{
				if (arr[i] <= value[j])
				{
					t = 1;
					break;
				}
			}
			*/
			if (t == 0)
			{
				value[index] = arr[i];
				find(n, m, arr, value, index + 1);
				value[index] = 0;

			}
		}
	}
}

int main(void)
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	int* arr = malloc(n * sizeof(int));
	int* value = calloc(m , sizeof(int));
	for (int i = 1; i < n+1; i++)
	{
		arr[i - 1] = i;
	}
	find(n, m, arr,value,0);
	free(arr);
	free(value);
	return 0;
}
