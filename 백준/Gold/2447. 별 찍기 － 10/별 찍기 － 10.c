
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
void none(int i,int j,int **arr,int r)
{
	for (int x = i+r; x < i+2*r; x++)
	{
		for (int y = j+r; y < j+2*r; y++)
		{
			arr[x][y] = 1;
		}
		
	}
}
void makestar(int n, int** arr,int act)
{

	int r = n / 3;
	
	for (int i = 0; i < act; i += n)
	{
		for (int j = 0; j < act; j += n)
		{
			none(i, j, arr, r);
		}
	}
	/*
	printf("debug \n");
	for (int i = 0; i < act; i++)
	{
		for (int j = 0; j < act; j++)
		{
			if (arr[i][j] == 0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
	*/
	if (r != 1)
		makestar(r, arr,act);
	else
	{
		
		for (int i = 0; i < act; i ++)
		{
			for (int j = 0; j < act; j ++)
			{
				if (arr[i][j] == 0)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	}

}
/*
문제 해결 야이디어
1.  가로 세로 크기만큼 정수 배열 선언하고 별이 출력되는 부분은 0 아닌 부분은 1로 변경하가
2. 1로 변경하는 부분을 함수로 설정하고 이용

*/
int main(void)
{
	int how;
	scanf("%d", &how);
	int** arr = (int**)calloc(how , sizeof(int*));
	for (int i = 0; i < how; i++)
	{
		arr[i] = calloc(how , sizeof(int));
	}
	makestar(how,arr,how);
	for (int i = 0; i < how; i++)
	{
		free(arr[i]);
	}
	free(arr);
	
	return 0;
}
