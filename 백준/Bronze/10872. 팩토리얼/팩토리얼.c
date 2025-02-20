
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int m(int n)
{
	int c = 1;
	for (int i = 2; i <= n; i++)
	{
		c *= i;
	}
	return c;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d",m(n));

	return 0;
}