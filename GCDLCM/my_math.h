#ifndef MY_MATH_H
#define MY_MATH_H

// 분수를 표현하는 구조체
typedef struct {
    int num; 
    int den; 
} Fraction;


int get_gcd(int a, int b);
int get_lcm(int a, int b);

// 분수 관련 함수
Fraction sim(Fraction f);                         
Fraction strFrac(char* str);                      
Fraction frac_gcd(Fraction f1, Fraction f2);      
Fraction frac_lcm(Fraction f1, Fraction f2);      
void printFrac(Fraction f, int isDec);  

#endif
