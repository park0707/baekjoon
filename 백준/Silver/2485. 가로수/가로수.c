#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
long long gaps(long long a, long long b)
{
	if (a == b)
	{
		return a;
	}
	if (a < b)
	{
		long long tmp = a;
		a = b;
		b = tmp;
	}
	long long r = a % b;
	a = b;
	if (r == 0)
		return b;
	while (1)
	{
		if (a % r != 0)
		{
			long long tmp = a;
			a = r;
			r = tmp % r;;
		}
		else
			return r;
	}
}
int main(void)
{
	long long how, n =0;
	scanf("%lld", &how);
	long long* arr = malloc(how * sizeof(long long));
	long long* gap = malloc((how-1) * sizeof(long long));
	for (int i = 0; i < how; i++)
	{
		scanf("%lld", &arr[i]);
	}
	for (int i = 0; i < how - 1; i++)
	{
		gap[i] = abs(arr[i] - arr[i + 1]);
	}
	long long current = gap[0];
	for (int i = 0; i < how - 1; i++)
	{
		current = gaps(current, gap[i]);
	}
	for (int i = 0; i < how - 1; i++)
	{
		n += (gap[i] / current) - 1;
	}
	printf("%lld", n);
	free(arr);
	free(gap);
	return 0;
}

