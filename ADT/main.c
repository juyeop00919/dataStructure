#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_fraction.h"

int main() {
    char s1[100], op, s2[100];

    if (scanf("%99s %c %99s", s1, &op, s2) != 3) {
        printf("Wrong Input.\n");
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
            printf("Wrong Input Type.\n");
            return 1;
    }

    printFrac(result);

    return 0;
}