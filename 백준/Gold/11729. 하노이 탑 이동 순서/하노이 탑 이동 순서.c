
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
int dub(int n)
{
	int r = 1;
	for (int i = 0; i < n; i++)
	{
		r *= 2;
	}
	return r;
}
void hanoi(int n, int a, int b, int c)
{
	if (n == 1)
	{
		printf("%d %d\n",a,c);
		return;
	}
	hanoi(n - 1, a, c, b);
	printf("%d %d\n", a, c);
	hanoi(n - 1, b, a, c);

}
int main(void)
{
	int how;
	scanf("%d", &how);
	printf("%d\n", dub(how) - 1);
	hanoi(how, 1, 2, 3);
	
	return 0;
}
