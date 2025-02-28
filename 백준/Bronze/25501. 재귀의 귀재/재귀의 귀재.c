
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
int how = 0;
int recursion(const char* s, int l, int r) {
	how++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char s[1005];
	for (int i = 0; i < n; i++)
	{
		how = 0;
		scanf("%s", s);
		printf("%d ", isPalindrome(s));
		printf("%d\n", how);
		
	}
	return 0;
}
