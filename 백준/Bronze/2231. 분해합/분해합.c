#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int doub(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        num *= 10;
    }
    return num;
}
int find(int n,int num)
{
    int len = 0, compare = n, m = n+1;
    if (num == n)
        return 0;
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    n = compare;
    
    if (len == 1)
    {
        compare = compare + n ;
    }
    else if (len == 2)
    {
        compare = compare + n / 10 + n % 10;
    }
    else 
    {
        for (int i = len;i>0;i--)
        {
            
            compare = compare + n / doub(i-1);
            n = n % doub(i-1);
        }
    }
    
    if (compare == num)
        return m-1;
    else
    {
        return find(m, num);
    }
    
}
int main(void)
{   
    int num,n=1;
    scanf("%d",  &num);
    printf("%d", find(n, num));
    
    return 0;
}
