#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int comapre(void *a, void* b)
{
	long long n1 = *(long long*)a;
	long long n2 = *(long long*)b;
	if (n1 < n2)
		return -1;
	else if (n1 > n2)
		return 1;
	else
		return 0;
	
}
int main(void)
{
	char s[1001];
	scanf("%s", s);
	int len = (int)strlen(s);
	long long base = 131;
	long long* prefix = malloc((len+1)*sizeof(long long));
	long long* power = malloc((len + 1) * sizeof(long long));

	prefix[0] = 0;
	power[0] = 1;
	for (int i = 0; i < len; i++)
	{
		prefix[i + 1] = prefix[i] * base + (long long)(s[i]);
		power[i + 1] = power[i] * base;
	}
	long long total = len * (len + 1) / 2;
	long long* hashes = malloc(total * sizeof(long long));

	long long index = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			hashes[index++] = prefix[j + 1] - prefix[i] * power[j - i + 1];
		}
	}
	qsort(hashes, total, sizeof(long long), comapre);

	long long dis = 0;
	if (total > 0)
	{
		dis = 1;
		for (int i = 1; i < total; i++)
		{
			if (hashes[i] != hashes[i - 1])
				dis++;
		}
	}
	printf("%lld", dis);
	free(prefix);
	free(power);
	free(hashes);
	return 0;
}

