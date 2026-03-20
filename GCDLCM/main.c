#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_math.h"

int main() {
    int num1, num2;

    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Wrong Input.\n");
        return 1;
    }

    printf("GCD : %d, ", get_gcd(num1, num2));
    printf("LCM : %d\n", get_lcm(num1, num2));

    return 0;
}
