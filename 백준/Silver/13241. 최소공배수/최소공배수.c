#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
long long find(long long a, long long b)
{
	long long r=1;
	long long n = a * b;
	if (a < b)
	{
		long long tmp = a;
		a = b;
		b = tmp;
	}
	if (a % b == 0)
	{
		return a;
	}
	else
	{
		r = a % b;
		a = b;
		while (1)
		{
			if (a % r == 0)
				break;
			else
			{
				long long tmp = a;
				a = r;
				r = tmp % r;
				
			}
		}
	}
	return n / r;
	
}
int main(void)
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", find(a, b));
	return 0;
}

