#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int main(void) {
    printf("----n----/--fibo--/---gcd---\n");
    for (int n = 5; n <= 93; n++) {

        clock_t sfibo = clock();

        unsigned long long fn = fib(n);
        unsigned long long fn_prev = fib(n - 1);
        unsigned long long gcd;

        clock_t efibo = clock();

		clock_t sgcd = clock();

		//GCD 계산을 100만번 수행하여 시간 측정
        for (int i = 0; i < 1000000; i++)
        {
            gcd = get_gcd(fn, fn_prev);
        }

		clock_t egcd = clock();

        //피보나치수열의 시간계산
        double ftime = (double)(efibo - sfibo) / CLOCKS_PER_SEC;

        //GCD계산의 시간계산
        double gtime = (double)(egcd - sgcd) / CLOCKS_PER_SEC;
       

        printf("%d\t%.3f\t", n, ftime*1000);
        printf("%.3f\n", gtime * 1000);

        //printf(" now Fibonacci (%d) : %llu    /      time: %.3f ms      / GCD : %llu \n", n, fn, time * 1000, gcd);
    }

    return 0;
}