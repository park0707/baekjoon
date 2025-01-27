#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int find(char arr1[8][8],char arr2[8][8])
{
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                sum++;
            }
        }
    }
    return sum;
}
int main(void)
{  
    int n, m,min=32;
    char x;
    char chess1[8][8];
    char chess2[8][8];
    char test[8][8];
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            if ((i + j) % 2 == 0) 
            {
                chess1[i][j] = 'W';
            }
            else 
            {
                chess1[i][j] = 'B';
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                chess2[i][j] = 'B';
            }
            else
            {
                chess2[i][j] = 'W';
            }
        }
    }
    scanf("%d %d", &n, &m);
    char** bord = (char**)malloc(n * sizeof(char*));
    
    for (int i = 0; i < n; i++)
    {
        bord[i] = (char*)malloc(m * sizeof(char));
        
    }
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            scanf("%c", &bord[i][j]);
        }
        getchar();
    }
    for (int i = 0; i <= n-8; i++)
    {
        for (int j = 0; j <= m-8; j++)
        {
            int sum = 0;
            for (int k = 0; k < 8; k++)
            {
                for (int p = 0; p < 8; p++)
                {
                    test[k][p] = bord[i + k][j + p];
                }
            }
            int n1 = find(test, chess1);
            int n2 = find(test,chess2);
            if (n1 > n2)
            {
                if (n2 < min)
                    min = n2;
            }
            else
            {
                if (n1 < min)
                    min = n1;
            }
     
        }
    }
   
   
    printf("%d", min);
    free(bord);
    

    
    return 0;
}
