#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int find(int a, int b)
{
	int n = 2, c = 1;;
	if (a == 1 || b == 1)
		return a * b;
	else if (a == b)
		return a;
	else
	{
		while (1)
		{
			if (a <= n || b <= n)
			{
				if (a % n != 0 || b % n != 0)
					break;
			}
			if (a % n != 0 || b % n != 0)
				n++;
			else
			{
				c *= n;
				a /= n;
				b /= n;
			}
		}
	}
	
	return c*a*b;
}
int main(void)
{
	int how, n, m;
	scanf("%d", &how);
	int* arr = malloc(how * sizeof(int));
	for (int i = 0; i < how; i++)
	{
		scanf("%d %d", &n, &m);
		arr[i] = find(n, m);
	}
	for (int i = 0; i < how; i++)
	{
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}

