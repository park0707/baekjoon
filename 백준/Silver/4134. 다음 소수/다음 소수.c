#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int check(long long n)
{
	
	
	if (n < 2)
		return 0;
	else if (n == 2 || n == 3)
		return 1;
	else if (n % 2 == 0 || n % 3 == 0)
		return 0;
	else
	{
		for (long long i = 5; i*i <= n; i+=6)
		{
			if (n % i == 0 || n%(i+2) == 0)
				return 0;
		}
	}
	return 1;
}
void find(long long n)
{
	if (n < 2)
	{
		printf("%lld\n", 2);
		return;
	}
	while (!check(n))
	{
		n++;
	}
	printf("%lld\n", n);
}
int main(void)
{
	long long how, n,max,min;
	scanf("%lld", &how);
	long long* arr = malloc(how * sizeof(long long));
	for (int i = 0; i < how; i++)
	{
		scanf("%lld", &arr[i]);
		find(arr[i]);
	}
	
    free(arr);
	return 0;
}

