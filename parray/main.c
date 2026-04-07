#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int main() {
    int N;
    int* arr; 
    int sum = 0, max, min;

    printf("Enter N : ");
    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int) * N);

    if (arr == NULL) { 
        return 1;
    }

    for (int i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1); 
    }

    // 정방향 출력
    printf("Forward Out : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 역방향 출력
    printf("Reverse Out: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 총합 최댓값 최솟값 출력
    max = min = *arr; 
    for (int i = 0; i < N; i++) {
        sum += *(arr + i);
        if (*(arr + i) > max) max = *(arr + i);
        if (*(arr + i) < min) min = *(arr + i);
    }

    printf("sum : %d\n", sum);
    printf("max : %d\n", max);
    printf("min : %d\n", min);

    free(arr);

    return 0;
}