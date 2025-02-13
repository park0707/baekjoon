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
void find(long long start,long long end)
{
	long long n = start;
	
	while (n<=end)
	{
		if(check(n))
			printf("%lld\n", n);
		n++;
	}
	
}
int main(void)
{
	long long start,end;
	scanf("%lld %lld", &start,&end);
	find(start, end);
	
	

	return 0;
}

