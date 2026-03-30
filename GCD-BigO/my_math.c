#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "my_math.h"

// 정수의 최대공약수
int get_gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 정수의 최소공배수
int get_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;

    return (abs(a) / get_gcd(a, b)) * abs(b);
}
