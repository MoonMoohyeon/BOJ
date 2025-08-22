#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;

int main() {

    scanf("%d", &N);

    int num = 1;
    int cnt = 0;
    while (1) {
        if (num * num <= N) {
            cnt++;
        }
        else {
            break;
        }
        num++;
    }

    printf("%d", cnt);

    return 0;
}