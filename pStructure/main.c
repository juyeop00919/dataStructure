#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students {
    char name[20];
    int num;
    int score;
};

int main() {
    int N = 0;
    scanf("%d", &N);

    struct Students* arr = (struct Students*)malloc(sizeof(struct Students) * N);

    FILE* fp;
    fp = fopen("C:\\Users\\Yeobbbing\\Desktop\\name_list.txt", "r");

    if (fp == NULL) {
        printf("Fail to open\n");
        return 0;
    }

    char* names[100];

    char file_buff[50];
    int name_count = 0;

    while (fgets(file_buff, sizeof(file_buff), fp) != NULL) {
        *(names + name_count) = (char*)malloc(strlen(file_buff) + 1);
        strcpy(*(names + name_count), (file_buff));
        name_count++;
    }

    for (int i = 0; i < N; i++) {
        int r = rand() % name_count;
        strcpy((arr + i)->name, *(names + r));
        (arr + i)->num = r + 1;
        (arr + i)->score = rand() % 101;
    }


    int max = arr->score;
    int min = arr->score;
    int max_num = 0;
    int min_num = 0;
    double sum = 0;

    for (int i = 0; i < N; i++)
    {
        if (max < (arr + i)->score) {
            max = (arr + i)->score;
            max_num = i;
        }
        if (min > (arr + i)->score) {
            min = (arr + i)->score;
            min_num = i;
        }
        sum += (arr + i)->score;
    }

    sum /= N;

    for (int i = 0; i < N; i++) {
        printf("Name: %sNum: %d\nScore: %d\n",
            (arr + i)->name,
            (arr + i)->num,
            (arr + i)->score);
    }
    printf("\n");
    printf("MAX : %d MIN: : %d AVG : %f\n\n", max, min, sum);

    printf("MAX Students INFO : \nName: %sNum: %d \nScore: %d\n\n",
        (arr + max_num)->name,
        (arr + max_num)->num,
        (arr + max_num)->score);

    printf("MIN Students INFO : \nName: %sNum: %d \nScore: %d\n",
        (arr + min_num)->name,
        (arr + min_num)->num,
        (arr + min_num)->score);
    free(arr);
    return 0;
}