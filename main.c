#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_fraction.h"

int main() {
    char s1[100], op, s2[100];

    if (scanf("%99s %c %99s", s1, &op, s2) != 3) {
        printf("입력형식이 맞지않습니다.\n");
        return 1;
    }

    Fraction f1 = strFrac(s1);
    Fraction f2 = strFrac(s2);
    Fraction result;

    switch (op) {
        case '+': result = add(f1, f2); break;
        case '-': result = minus(f1, f2); break;
        case '*': result = multi(f1, f2); break;
        case '/': result = divide(f1, f2); break;
        default:
            printf("연산자가 잘못되었습니다..\n");
            return 1;
    }

    printFrac(result);

    return 0;
}