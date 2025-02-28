
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
int taget = 0;
int t = 0;
int c = 0;
void merge(int* arr, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = malloc(n1 * sizeof(int));
	int* R = malloc(n2 * sizeof(int));
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[left+i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + j + 1];
	}
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			taget++;
			//printf("저장 시행 횟수 %d and 저장된 숫자 : %d\n", taget, L[i]);
			if (taget == t)
			{
				c = 1;
				int tmp =  L[i];

				free(L);
				free(R);
				printf("%d", tmp);
				return;
			}
			arr[k++] = L[i++];
		}
		else
		{
			taget++;
			//printf("저장 시행 횟수 %d and 저장된 숫자 : %d\n", taget, R[j]);
			if (taget == t)
			{
				c = 1;
				int tmp = R[j];

				free(L);
				free(R);
				printf("%d", tmp);
				return;
			}
			arr[k++] = R[j++];
		}

	}
	while (i < n1) 
	{
		taget++;
		//printf("저장 시행 횟수 %d and 저장된 숫자 : %d\n", taget, L[i]);
		if (taget == t)
		{
			c = 1;
			int tmp = L[i];c = 1;

			free(L);
			free(R);
			printf("%d", tmp);
			return;
		}
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		taget++;
		//printf("저장 시행 횟수 %d and 저장된 숫자 : %d\n", taget, R[j]);
		if (taget == t)
		{
			c = 1;
			int tmp = R[j];

			free(L);
			free(R);
			printf("%d", tmp);
			return;
		}
		arr[k++] = R[j++];
	}
	free(L);
	free(R);
	
}
void mergesort(int* arr, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = left + (right - left) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	
}

int main(void)
{
	int how;
	scanf("%d %d", &how, &t);
	int* arr = malloc(how * sizeof(int));
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergesort(arr, 0, how - 1);
	if (taget > how && c == 0)
	{
		printf("-1");
	}
	free(arr);
	return 0;
}
