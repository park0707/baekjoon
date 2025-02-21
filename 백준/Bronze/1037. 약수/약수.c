
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main(void)
{
	int how;
	int arr[50];
	scanf("%d", &how);
	for (int i = 0; i < how; i++)
	{
		scanf("%d", &arr[i]);
		
		
	}
	if (how == 1)
		printf("%d", arr[0] * arr[0]);
	else if (how == 2)
		printf("%d", arr[0] * arr[1]);
	else
	{
		qsort(arr, how, sizeof(int), compare);
		printf("%d", arr[0] * arr[how - 1]);
	}
	

	

	return 0;
}