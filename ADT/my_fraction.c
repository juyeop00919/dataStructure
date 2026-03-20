#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_fraction.h"

// 최대공약수
int get_gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Fraction sim(Fraction f) {
    if (f.den == 0) {
        printf("분모는 0이 될 수 없습니다.\n");
        exit(1);
    }
    int common = get_gcd(f.num, f.den);
    f.num /= common;
    f.den /= common;
    
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    return f;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction res;
    res.num = (f1.num * f2.den) + (f2.num * f1.den);
    res.den = f1.den * f2.den;
    return sim(res);
}

Fraction minus(Fraction f1, Fraction f2) {
    Fraction res;
    res.num = (f1.num * f2.den) - (f2.num * f1.den);
    res.den = f1.den * f2.den;
    return sim(res);
}

Fraction multi(Fraction f1, Fraction f2) {
    Fraction res;
    res.num = f1.num * f2.num;
    res.den = f1.den * f2.den;
    return sim(res);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction res;
    res.num = f1.num * f2.den;
    res.den = f1.den * f2.num;
    return sim(res);
}

Fraction strFrac(char* str) {
    Fraction f;

    //분수
    if (strchr(str, '/') != NULL) {
        sscanf(str, "%d/%d", &f.num, &f.den);
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


void printFrac(Fraction f) {
    if (f.den == 1) {
        printf("%d\n", f.num); 
    } else {
        printf("%d/%d\n", f.num, f.den);
    }
}