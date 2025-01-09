#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int doublevalue(int a, int b)
{
    int value = 1;
    for (int i = 0; i < b; i++)
    {
        
        value *= a;
        
    }
    
    return value;
}
int main(void)
{   
    int type,total=0;
    char input[100] = { 0 };
    scanf("%s %d", input, &type);
    int len = strlen(input);
    int* value = malloc(len * (sizeof(int)));
    
    for (int i = 0; i < len; i++)
    {
        
        
        if ((input[i]-'0') > 9)
        {
            value[i] = input[i] - 55;
            
            
        }
        else
        {
            value[i] = (input[i]-'0');
            
        }
            
        
    }
    
    for (int i = 0; i <len; i++)
    {
        total += value[i] * doublevalue(type,len-i-1);
    }
    printf("%d", total);
    return 0;
}
