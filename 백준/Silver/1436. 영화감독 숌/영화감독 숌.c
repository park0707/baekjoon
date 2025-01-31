#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int doub(int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= 10;
    }
    return result;
}
int check(int n)
{
    int len = log10(n);
    int* arr = malloc((len + 1) * sizeof(int));
    int c = 0;
    int how = 0;
    for (int i = doub(len); i > 0; i /= 10)
    {
        
        arr[c] = n / i;
        n %= i;
        c++;
    }
    
    for (int i = 0; i < len - 1; i++)
    {
        
        if (arr[i] == 6 && arr[i + 1] == 6 && arr[i + 2] == 6)
        {
            how++;
        }
    }
    
    if (how == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
    free(arr);
}
void plus(int *n,int *num)
{
    
    int len = log10(*n);
    int ifresult = *n;
    int c = 0;
    int how = 0;
    int* arr = malloc((len + 1) * sizeof(int));
    for (int i = doub(len); i > 0; i /= 10)
    {
        arr[c] = *n / i;
        *n %= i;
        c++;
    }
    
    
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] == 6 && arr[i + 1] == 6 && arr[i + 2] == 6)
        {
            for (int j = i + 3; j < len+1; j++)
            {
                arr[j] = 0;
                how++;
            }
            break;
        }
    }
   

    if (how == 1)
    {
        if (how * 9 >= (*num-=1))
        {
            
            int result = 0;
            int c = 0;
            for (int i = doub(len); i > 0; i /= 10)
            {
                
                result += arr[c] * i;
                c++;
            }
            
            result += *num;
            *n = result;
            *num = 0;
        }
        else
        {
            *num += 1;
            *num -= 9;
            *n = ifresult;
        }
    }
    else
    {
        int hownum = 1;
        for (int i = 1; i < how; i++)
        {
            
            hownum =  doub(i) + hownum;

        }
        if (hownum * 9 >= (*num-=1))
        {
            
            int result = 0;
            int c = 0;
            for (int i = doub(len); i > 0; i /= 10)
            {
                
                result += arr[c] * i;
                c++;
            }
            
            result += *num;
            *n = result;
            *num = 0;
        }
        else 
        {
            *num += 1;
            *num = *num - 9*hownum;
            *n = ifresult;
        }
    }
    
    
    free(arr);
}
int main(void)
{  
    int n=6,num;
    scanf("%d", &num);
    if (num <= n)
    {
        int i = (num - 1) * 1000 + 666;
        printf("%d", i);
        return 0;
    }
    else
    {
        int s = 666;
        while (1)
        {
            if (num <= 1)
            {
                printf("%d", s);
                return 0;
            }
            s += 1000;
            num--;
            if (check(s) == 0)
            {
                
                continue;
            }
            else
            {
                
                plus(&s, &num);
            }
        }
        
    }
    
    
    return 0;
}
