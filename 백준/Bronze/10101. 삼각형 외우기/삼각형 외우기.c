#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{   
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (a == 60 && b == 60 && c == 60)
        printf("Equilateral");
    else if ((a + b + c) == 180 && (a == b || b == c || c == a))
        printf("Isosceles");
    else if ((a + b + c) == 180 && (a != b && b != c && c != a))
        printf("Scalene");
    else if((a + b + c) != 180)
        printf("Error");
    return 0;
}
