#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int main(void)
{
	int* arr = malloc(1000001 * sizeof(int));
	for (int i = 0; i < 1000001; i++)
		arr[i] = 1;
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (arr[i] == 1)
		{
			for (int j = i * i; j <= 1000000; j += i)
				arr[j] = 0;
		}
	}
	int how, n,t=0;
	scanf("%d", &how);
	for (int i = 0; i < how; i++)
	{
		t = 0;
		scanf("%d", &n);
		for (int j = 2; j <= n / 2; j++)
		{
			if (arr[j] == 1 && arr[n - j] == 1)
				t++;
		}
		printf("%d\n", t);
		
	}
	
	free(arr);
	return 0;
}

