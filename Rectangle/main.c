#include <stdio.h>
#include <string.h> 
#include "rectangle.h"

int main(int c, char** v) {
    if (c != 3) {
        printf("Usage: %s <num1> <num2>\n", v[0]);
        return 1;
    }


    Fraction width = strFrac(v[1]);
    Fraction height = strFrac(v[2]);

    Fraction sum = add(width, height);

    //분수식으로 계산하기 위해 2를 분수로 표현
    Fraction two = { 2, 1 };

    Fraction perimeter = multi(sum, two);

    Fraction area = multi(width, height);

    printf("Perimeter: ");
    printFrac(perimeter);

    printf(", Area: ");
    printFrac(area);

    printf("\n");

    return 0;
}
