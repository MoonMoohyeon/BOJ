#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N, M;
int arr[15001];

int comp(const void* left, const void* right) {
    int L = *(int*)left;
    int R = *(int*)right;

    if (L > R) return 1;
    if (L < R) return -1;
    return 0;
}

int main(int argc, char** argv) {
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(arr[0]), comp);

    /*for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }*/

    int lptr = 0;
    int rptr = N - 1;
    int ans = 0;
    while (lptr < rptr) {
        int tempsum = arr[lptr] + arr[rptr];
        if (tempsum < M) lptr++;
        else if (tempsum > M) rptr--;
        else {
            ans++;
            lptr++;
        }
    }

    printf("%d", ans);

    return 0;
}