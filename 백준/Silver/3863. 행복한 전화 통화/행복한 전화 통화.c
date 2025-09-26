#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int call_starts[10000];
int call_durations[10000];

int main(void) {
    int N, M;

    while (scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)) {

        for (int i = 0; i < N; ++i) {
            int src, dst;
            scanf("%d %d %d %d", &src, &dst, &call_starts[i], &call_durations[i]);
        }

        // M개의 도청 구간에 대해 계산
        for (int i = 0; i < M; ++i) {
            int interval_start, interval_duration;
            scanf("%d %d", &interval_start, &interval_duration);

            int interval_end = interval_start + interval_duration;
            int overlap_count = 0;

            // 모든 통화를 확인하며 현재 도청 구간과 겹치는지 검사
            for (int j = 0; j < N; ++j) {
                int call_end = call_starts[j] + call_durations[j];

                // 겹치는지 확인하는 핵심 조건
                // (통화 시작 < 구간 끝) AND (통화 끝 > 구간 시작)
                if (call_starts[j] < interval_end && call_end > interval_start) {
                    overlap_count++;
                }
            }
            printf("%d\n", overlap_count);
        }
    }

    return 0;
}