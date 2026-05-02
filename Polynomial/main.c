#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"
#include <string.h>

int main() {
    //polynomial* p;
    //p = createArrayList(100);
    //addItemPolynomial(p, (elementType) { 4, 0 });
    //addItemPolynomial(p, (elementType) { 2, 1 });
    //addItemPolynomial(p, (elementType) { 3, 2 });
    //printPolynomial(p);
    //polynomial* p2;
    //p2 = createArrayList(100);
    //addItemPolynomial(p2, (elementType) { 4, 3 });
    //addItemPolynomial(p2, (elementType) { 5, 0 });
    //printPolynomial(p2);
    //polynomial* p3 = addPolynomial(p, p2);
    //printPolynomial(p3);
    char input1[500], input2[500];

    printf("Enter p1 (ex: 3X^2+2X^1+1X^0): ");
    scanf("%s", input1);
    printf("Enter p2 (ex: 3X^2+2X^1+1X^0): ");
    scanf("%s", input2);

    polynomial* p1 = createPolynomial(100);
    polynomial* p2 = createPolynomial(100);

    char* ptr = input1;
    int coef, expo, offset;

    while (sscanf(ptr, "%dX^%d%n", &coef, &expo, &offset) == 2) {
        addItemPolynomial(p1, (elementType) { coef, expo });
        ptr += offset; 
        if (*ptr == '+') ptr++; 
    }

    ptr = input2;
    while (sscanf(ptr, "%dX^%d%n", &coef, &expo, &offset) == 2) {
        addItemPolynomial(p2, (elementType) { coef, expo });
        ptr += offset;
        if (*ptr == '+') ptr++;
    }

    polynomial* result = multiplyPolynomial(p1, p2);

    printf("\nOutput: ");
    printPolynomial(result);

    destroyArrayList(p1);
    destroyArrayList(p2);
    destroyArrayList(result);
    
    return 0;
}