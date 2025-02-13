#include <stdio.h>
#include <math.h>

// 소수 판별 함수
int is_prime(long long n) {
    if (n < 2)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// 다음 소수 찾기 함수
void find_next_prime(long long n) {
    if (n <= 1) {
        printf("2\n");
        return;
    }
    while (!is_prime(n)) {
        n++;
    }
    printf("%lld\n", n);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        find_next_prime(n);
    }
    return 0;
}
