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
		return b;
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
	return  r;
	
}
int main(void)
{
	long long a, b,n,m,x,y,r;
	scanf("%lld %lld", &a, &b);
	scanf("%lld %lld", &n, &m);
	x = a * m + n * b;
	y = m * b;
	r = find(x, y);
	printf("%lld %lld", x / r, y / r);
	return 0;
}

