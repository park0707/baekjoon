#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int type;
    int input;
    scanf("%d %d", &input, &type);
    int rest = 0;
    int i = 0;
    char arr[100] = { 0 };
    
    while(1)
    {
        if (input >= type)
        {
            
            rest = input % type;
            if (rest > 9)
                arr[i] = rest + 55;
            else
            {
                arr[i] = rest + '0';
            }
                
            
            input = input / type;
            i++;

        }
        else
        {
            rest = input % type;
            if (rest > 9)
                arr[i] = rest + 55;
            else
            {
                arr[i] = rest + '0';
            }
            
            input = input / type;
            i++;
            break;
        }
        
        
       
    }
    
    
    for (int i = strlen(arr)-1; i >=0; i--)
    {
        printf("%c", arr[i]);
    }
    
    return 0;
}
