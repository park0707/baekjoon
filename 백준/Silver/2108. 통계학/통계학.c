
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct num
{
	int n;
	int how;
}num;
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void m1(int* arr, int how)
{
	double sum=0;
	for (int i = 0; i < how; i++)
	{
		sum += arr[i];
	}
	
	printf("%d\n", (int)round(sum / how));
	
}
void m2(int* arr, int how)
{
	qsort(arr, how, sizeof(int), compare);
	int n = how / 2;
	
	printf("%d\n", arr[n]);

}
void m3(int* arr, int how)
{
	if (how == 1)
	{
		printf("%d\n", arr[0]);
		return;
	}
	num* number = calloc(how , sizeof(num));
	int* ex = malloc(how * sizeof(int));
	int n = arr[0];
	int j = 0;
	number[0].n = arr[0];
	for (int i = 0; i < how; i++)
	{
		if (n == arr[i])
		{
			number[j].how++;

		}
		else
		{
			n = arr[i];
			j++;
			number[j].n = n;
			number[j].how++;
		}
	}
	//printf("j is %d\n",j);

	int min = number[0].how;
	int r = number[0].n;
	int test = 0;
	for (int i = 1; i <= j; i++)
	{
		if (number[i].how > min)
		{
			min = number[i].how;
			r = number[i].n;
			test = 0;
		}
		else if (number[i].how == min)
			test = 1;
	}
	int t = 0;
	
	if (test == 1)
	{
		for (int i = 0; i <= j; i++)
		{
			if (t == 2)
				break;
			if (number[i].how == min)
			{
				ex[t] = number[i].n;
				t++;
			}
		}
		printf("%d\n", ex[1]);
	}
	else
	{
		printf("%d\n", r);
	}
	free(number);
	free(ex);
}
void m4(int *arr,int how)
{
	if (how == 1)
		printf("0");
	else
		printf("%d", arr[how - 1] - arr[0]);
}
int main(void)
{
	int how;
	scanf("%d", &how);
	int* arr = malloc(how * sizeof(int));
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &arr[i]);
	}
	//printf("m1 is");
	m1(arr, how);
	//printf("m2 is");
	m2(arr, how);
	//printf("m3 is");
	m3(arr, how);
	//printf("m4 is");
	m4(arr, how);
	free(arr);
	return 0;
}
