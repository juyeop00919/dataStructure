#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef struct{
    int num; //분자
    int den; //분모
} Fraction;

Fraction sim(Fraction f);
Fraction add(Fraction f1, Fraction f2);
Fraction minus(Fraction f1, Fraction f2);
Fraction multi(Fraction f1, Fraction f2);
Fraction divide(Fraction f1, Fraction f2);
Fraction strFrac(char* str);
void printFrac(Fraction f);

#endif 