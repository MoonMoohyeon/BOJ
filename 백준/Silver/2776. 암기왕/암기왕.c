#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, N, M;
int note[1000001];

int comp(const void* first, const void* second) {
    return (*(int*)first > *(int*)second);
}

int search(int target) {
    int start = 0;
    int end = N - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (target == note[mid]) return 1;

        if (target < note[mid]) end = mid - 1;
        else start = mid + 1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {

        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            int num;
            scanf("%d", &num);
            note[i] = num;
        }
        qsort(note, N, sizeof(int), comp);

        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            int num;
            scanf("%d", &num);
            printf("%d\n", search(num));
        }
    }

    return 0;
}
