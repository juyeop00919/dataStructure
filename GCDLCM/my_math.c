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

//기약분수
/*
Fraction sim(Fraction f) {
    if (f.den == 0) return f;

    int gcd = get_gcd(f.num, f.den);
    f.num /= gcd;
    f.den /= gcd;


    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    return f;
}



Fraction strFrac(char* str) {
    Fraction f;

    //분수
    if (strchr(str, '/') != NULL) {
        sscanf(str, "%d/%d", &f.num, &f.den);
        if (f.den == 0) {
            printf("분모가 0이 될 수 없습니다..\n");
            f.num = 0; f.den = 1;
        }
    }

    //소수
    else if (strchr(str, '.') != NULL) {
        double val;
        char* dot = strchr(str, '.');
        int len = strlen(dot + 1);
        int multiplier = 1;

        sscanf(str, "%lf", &val);

        for (int i = 0; i < len; i++) {
            multiplier *= 10;
        }

        f.num = (int)(val * multiplier);
        f.den = multiplier;
    }

    //정수
    else {
        sscanf(str, "%d", &f.num);
        f.den = 1;
    }

    return sim(f);
}


Fraction frac_gcd(Fraction f1, Fraction f2) {
    Fraction result;
    result.num = get_gcd(f1.num, f2.num);
    result.den = get_lcm(f1.den, f2.den);
    return sim(result);
}


Fraction frac_lcm(Fraction f1, Fraction f2) {
    Fraction result;
    result.num = get_lcm(f1.num, f2.num);
    result.den = get_gcd(f1.den, f2.den);
    return sim(result);
}




void printFrac(Fraction f, int isDec) {
    if (f.den == 1) {
        printf("%d", f.num); 
    }

    else if (isDec == 1) {
		printf("%g", (double)f.num / f.den);
    }

    else {
        printf("%d/%d", f.num, f.den);
    }
}

*/