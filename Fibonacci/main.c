#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int main(void) {

    for (int n = 1; n <= 93; n++) {
        unsigned long long fn = fibonacci(n);
        unsigned long long fn_prev = fibonacci(n - 1);
        unsigned long long gcd;

        clock_t start = clock();

        gcd = get_gcd(fn, fn_prev);

        // 너무 빨리 끝나는 나머지 반복 부하 
         for (int i = 0; i < 1000000; i++)
         {
             gcd = get_gcd(fn, fn_prev);
         }


        clock_t end = clock();


        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%.3f\n", n, time*1000);

        //printf(" now Fibonacci (%d) : %llu / GCD : %llu / time: %f ms \n", n, fn, gcd, time*1000);
    }

    return 0;
}