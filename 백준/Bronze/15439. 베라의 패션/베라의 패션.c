
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	if (n == 1)
		printf("0");
	else
	{
		printf("%d", n * (n - 1));
	}
	return 0;
}