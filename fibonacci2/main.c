#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//순환적 방법
unsigned long long  Iterative(int n) {
	unsigned long long  a = 1, b = 1, c = 1;

	if (n == 0 || n == 1)
		return 1;
	else if (n == 2)
		return 2;

	for (int i = 3; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

//재귀적 방법
unsigned long long Recursive(int n) {

	if (n <= 2) return 1;
	return Recursive(n - 1) + Recursive(n - 2);
	
}

int main() {
	int N = 49;

	printf("Recursive: \n");
	printf("F(n) ----   N    ---- Time \n");
	for (int i = 0; i < N; i++)
	{
		clock_t sre = clock();
		printf("%llu ", Recursive(i));
		clock_t ere = clock();
		double retime = (double)(ere - sre) / CLOCKS_PER_SEC;
		printf("%d     %f\n", i, retime);
	}



	printf("Iterative : \n");
	printf("F(n) ----   N    ---- Time \n");
	for (int i = 0; i < N; i++)
	{
		clock_t sie = clock();
		printf("%llu", Iterative(i));
		clock_t eie = clock();
		double itime = (double)(eie - sie) / CLOCKS_PER_SEC;
		printf("%d     %f\n", i, itime);
	}


	return 0;
}
