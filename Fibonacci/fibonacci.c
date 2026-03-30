#include "fibonacci.h"

unsigned long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2); 
}


unsigned long long get_gcd(unsigned long long a,unsigned long long b) {
    if (b == 0) return a;
    return get_gcd(b, a % b);
}
