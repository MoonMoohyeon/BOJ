#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long

int N;
int arr[10];

int calsum(int start, int end) {
    int ret = 1;
    for (int i = start; i <= end; ++i) {
        ret *= arr[i];
    }

    return ret;
}

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    // 10개를 4개의 그룹으로 나누기
    int ans = 0;
    for (int i = 0; i <= N - 4; ++i) {
        for (int j = i + 1; j <= N - 3; ++j) {
            for (int k = j + 1; k <= N - 2; ++k) {
                int p1 = calsum(0, i);
                int p2 = calsum(i + 1, j);
                int p3 = calsum(j + 1, k);
                int p4 = calsum(k + 1, N - 1);

                int sum = p1 + p2 + p3 + p4;
                //printf("%d %d %d %d %d\n", p1, p2, p3, p4, sum);
                if (sum > ans) ans = sum;
            }
        }
    }

    printf("%d", ans);

    return 0;
}