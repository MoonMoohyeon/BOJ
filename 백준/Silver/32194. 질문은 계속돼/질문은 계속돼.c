#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long

int N;
int prefix_sum[200002];

int main(int argc, char* argv[]) {

    scanf("%d", &N);
    prefix_sum[1] = 1;

    for (int t = 2; t <= N + 1; ++t) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int isYes = 0;
        int range_len = y - x + 1;

        // x부터 y까지 예의 개수
        int cnt = prefix_sum[y] - prefix_sum[x - 1];

        if (type == 1) { // 모두 예인지 확인
            if (cnt == range_len) {
                isYes = 1;
            }
        }
        else if(type == 2) { // 타입이 2일 땐 모두 아니오인지 확인 -> 대답은 Yes
            if (cnt == 0) {
                isYes = 1;
            }
        }

        if (isYes) {
            printf("Yes\n");
            // 현재 t번째 답이 예이므로 이전 누적 합 + 1
            prefix_sum[t] = prefix_sum[t - 1] + 1;
        }
        else {
            printf("No\n");
            // 현재 t번째 답이 아니오이므로 누적 합은 동일
            prefix_sum[t] = prefix_sum[t - 1];
        }
    }

    return 0;
}