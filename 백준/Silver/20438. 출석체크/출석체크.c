#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N, K, Q, M;
int S, E;
int sleeping[60000];
int check[60000];
int prefix_sum[60000];

int main(int argc, char** argv) {
    
    scanf("%d %d %d %d", &N, &K, &Q, &M);
    int student_num;

    for (int i = 0; i < K; ++i) {
        scanf("%d", &student_num);
        sleeping[student_num] = 1;
    }

    for (int i = 0; i < Q; ++i) {
        scanf("%d", &student_num);
        if (sleeping[student_num]) { // 조는 학생 건너 뛰기
            continue;
        }
        for (int j = student_num; j <= N + 2; j += student_num) {
            if (!sleeping[j]) {
                check[j] = 1;
            }
        }
    }

    for (int i = 3; i <= N + 2; ++i) {
        if (!check[i]) {
            prefix_sum[i] = prefix_sum[i - 1] + 1; // 출석한 경우
        }
        else {
            prefix_sum[i] = prefix_sum[i - 1];
        }
    }

    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &S, &E);
        int ans = prefix_sum[E] - prefix_sum[S - 1];
        printf("%d\n", ans);
    }

    return 0;
}