
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
long long m(int n,int c)
{
	long long r = 1;
	int t = n;
	if (c - n < n)
		t = c-n;
	for (int i = 1; i <= t; i++)
	{
		r = r * (c - i + 1) / (i);
		
	}
	return r;
}

int main(void)
{
	int n,c,how;
	scanf("%d", &how);
	for (int i = 0; i < how; i++)
	{
		scanf("%d %d", &n, &c);
		if (n == 1)
			printf("%d\n",n*c);
		else
		{
			printf("%lld\n", m(n,c) );
		}
		
	}
	

	return 0;
}