#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int how,check=1,n=2;
    scanf("%d", &how);
    if (how == 1)
    {
        printf("1/1");
    }
    else
    {
        while (1)
        {
            check += 1 * n;
            if (how <= check)
            {
                check -= 1 * n;
                int count = how - check;
                if (n % 2 == 0)
                {
                    int x = 0, y = n - 1;
                    if (count == 1)
                    {
                        printf("%d/%d", x+1, y+1);
                        break;
                    }
                    else
                    {
                        for (int i = 0; i < count - 1; i++)
                        {
                            x++;
                            y--;
                        }
                        printf("%d/%d", x+1, y+1);
                        break;
                    }
                }
                else
                {
                    int x = n-1, y =0;
                    if (count == 1)
                    {
                        printf("%d/%d", x+1, y+1);
                        break;
                    }
                    else
                    {
                        for (int i = 0; i < count - 1; i++)
                        {
                            x--;
                            y++;
                        }
                        printf("%d/%d", x+1, y+1);
                        break;
                    }
                }
            }
            else
                n++;
        }
    }
    
    return 0;
}
