#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int quvalue(int arr[], int a)
{
    
    
    while (1)
    {
        if (a >= 25)
        {
            
            arr[0] = a / 25;
            a %= 25;
        }
        else
            return a;
    }
    
        
}
int divalue(int arr[], int a)
{
    

    while (1)
    {
        if (a >= 10)
        {
            
            arr[1] = a/10;
            a %= 10;
        }
        else
            return a;
    }


}
int nivalue(int arr[], int a)
{


    while (1)
    {
        if (a >= 5)
        {
            
            arr[2] = a/5;
            a %= 5;
        }
        else
            return a;
    }


}
int pevalue(int arr[], int a)
{
    arr[3] = a;
    return 0;
    
        



}
int main(void)
{   
    int how;
    
    scanf("%d", &how);
    int* arr = malloc(how * sizeof(int));
    for (int i = 0; i < how; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < how; i++)
    {
        int value[4] = { 0 };
        int qu = 0, di = 0, ni = 0, pe = 0;
        int money = arr[i];
        while (money != 0)
        {
            money = quvalue(value, money);
            money = divalue(value, money);
            
            money = nivalue(value, money);
            
            money = pevalue(value, money);
        }
        printf("%d %d %d %d\n", value[0], value[1], value[2], value[3]);
       
    }
    
    return 0;
}
