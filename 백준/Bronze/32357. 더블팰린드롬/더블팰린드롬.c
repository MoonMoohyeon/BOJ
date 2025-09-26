#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int N;

void swap(char* first, char* second) {
    char tmp = *first;
    *first = *second;
    *second = tmp;
}

void reverse(char target[501], int len) {
    for (int i = 0; i < len / 2; ++i) {
        swap(&target[i], &target[len - 1 - i]);
    }
}

int main(void) {
    scanf("%d", &N);

    int pal_cnt = 0;
    char str[1001];
    for (int i = 0; i < N; ++i) {
        scanf("%s", str);

        int len = strlen(str);

        char first_half[501];
        strncpy(first_half, str, len / 2);
        first_half[len / 2] = '\0';

        char second_half[501];
        strncpy(second_half, str + len / 2, len / 2);
        second_half[len / 2] = '\0';
        reverse(second_half, len / 2);
        //printf("%s %s\n", first_half, second_half);
        if (strcmp(first_half, second_half) == 0) pal_cnt++;
    }

    //printf("%d\n", pal_cnt);
    printf("%d", pal_cnt * (pal_cnt - 1));

    return 0;
}