
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
long long method(int n)
{
	if (n == 0)
	{

		return 1;
	}
	else
	{
		return n * method(n - 1);
	}

}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%lld", method(n));
	return 0;
}


