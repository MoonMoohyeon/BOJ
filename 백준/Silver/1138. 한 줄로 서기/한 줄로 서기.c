#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N;
int lef[11];
int res[10] = { 0 };

int main(int argc, char* argv[]) {

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &lef[i]);
    }

    // 키가 1인 사람부터 N인 사람까지 순서대로 배치
    for (int i = 1; i <= N; ++i) {
        int cnt = lef[i];
        int empty = 0;

        for (int j = 0; j < N; ++j) {
            if (res[j] == 0 && empty == cnt) { // res = 0은 빈 칸
                res[j] = i;
                break;
            }

            if (res[j] == 0) {
                empty++;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }

    return 0;
}