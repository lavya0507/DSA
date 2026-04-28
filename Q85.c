#include <stdio.h>

long long findIntegerSqrt(long long n) {
    if (n == 0 || n == 1) return n;

    long long start = 1, end = n, ans = 0;
    
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (mid <= n / mid) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    
    if (n < 0) {
        printf("Invalid input\n");
    } else {
        printf("%lld\n", findIntegerSqrt(n));
    }
    
    return 0;
}
