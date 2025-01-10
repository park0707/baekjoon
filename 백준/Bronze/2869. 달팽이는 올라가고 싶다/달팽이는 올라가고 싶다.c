#include <stdio.h>
#include <math.h>

int main(void)
{
    int up, down, he;
    scanf("%d %d %d", &up, &down, &he);

    
    int days = (int)ceil((double)(he - up) / (up - down)) + 1;

    printf("%d\n", days);
    return 0;
}
