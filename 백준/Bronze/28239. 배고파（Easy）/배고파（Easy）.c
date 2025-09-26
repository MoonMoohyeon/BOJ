#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define ll long long

ll N, M;
ll powerTable[64];

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < 64; ++i) {
        powerTable[i] = pow(2, i);
    }

    for (int t = 0; t < N; ++t) {
        scanf("%lld", &M);
        int x = 0, y = 0;
        int flag = 0;
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 64; ++j) {
                if (powerTable[i] + powerTable[j] == M) {
                    printf("%d %d\n", i, j);
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
    }

    return 0;
}