#include <stdio.h>

#define N 3 

int main() {
    int magic[N][N] = { 0 };
    int row = 0;
    int col = N / 2; 
    int num = 1;

    // 마방진 채우기
    while (num <= N * N) {
        magic[row][col] = num++;
        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (magic[next_row][next_col] != 0) {
            row = (row + 1) % N; // 이미 숫자가 있으면 아래로 이동
        }
        else {
            row = next_row;
            col = next_col;
        }
    }

    // 1. 배열 전체 출력
    printf("%d*%d Out :\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", magic[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 2. 검증을 위한 합계 출력
    printf(" Result \n");

    // 가로 합
    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) rowSum += magic[i][j];
        printf("Row sum (%d) : %d\n", i + 1, rowSum);
    }

    // 세로 합
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) colSum += magic[i][j];
        printf("Column sum (%d): %d\n", j + 1, colSum);
    }

    // 대각선 합 (우하향)
    int diag1 = 0;
    for (int i = 0; i < N; i++) diag1 += magic[i][i];
    printf("Diagonal sum : %d\n", diag1);

    // 대각선 합 (우상향)
    int diag2 = 0;
    for (int i = 0; i < N; i++) diag2 += magic[i][N - 1 - i];
    printf("Diagonal sum : %d\n", diag2);

    return 0;
}