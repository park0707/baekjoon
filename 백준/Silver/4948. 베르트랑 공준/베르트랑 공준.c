#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
long long check(long long n)
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
long long find(long long n)
{
	
		
	//printf("find was work\n");
	long long end = 2 * n;
	long long c = 0;
	n++;
	while (n<=end)
	{
		if (check(n))
			c++;
		n++;
	}
	return c;
}
int main(void)
{
	long long n=1;
	
	while (1)
	{
		scanf("%lld", &n);
		if (n == 0)
			break;
		printf("%lld\n", find(n));

	}
	
	

	return 0;
}

