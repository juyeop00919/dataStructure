#include "fibonacci.h"

unsigned long long fibonacci(int n) {
    if (n <= 1) return (unsigned long long)n;
    unsigned long long a = 0, b = 1, tmp;
    for (int i = 2; i <= n; i++) {
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}

unsigned long long get_gcd(unsigned long long a,unsigned long long b) {
    if (b == 0) return a;
    return get_gcd(b, a % b);
}
