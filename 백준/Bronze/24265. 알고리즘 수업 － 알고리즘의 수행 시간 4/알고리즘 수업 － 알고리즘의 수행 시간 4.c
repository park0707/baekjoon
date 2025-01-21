#include <stdio.h>
int main(void)
{
    long long n,c=0;;
    scanf("%lld",&n);
    for(int i=1;i<n;i++)
    {
        c+= i;
    }
    printf("%lld\n",c);
    printf("%d",2);
    return 0;
    
}