
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int dub(int n)
{
	int c = 1;
	for (int i = 0; i < n; i++)
	{
		c *= 2;
	}
	return c;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d",dub(n));

	return 0;
}