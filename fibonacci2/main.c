#include <stdio.h>
#include <stdlib.h>

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

	//printf("Recursive: %llu\n", Recursive(N));
	//printf("Iterative: %llu\n", Iterative(N));

	printf("Recursive: ");
	for (int i = 0; i < N; i++)
	{
		printf("%llu ", Recursive(i));
	}

	printf("Iterative : ");
	for (int i = 0; i < N; i++)
	{
		printf("%llu", Iterative(i));
	}
	return 0;
}