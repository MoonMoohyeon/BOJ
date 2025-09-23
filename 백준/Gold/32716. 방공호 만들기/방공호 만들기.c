#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000000
long long arr[MAX + 1];
int main(int argc, char* argv[]) {

    int N;
    scanf("%d", &N);

    if (N < 4) {
        printf("0");
        return 0;
    }

    arr[4] = arr[5] = 1;
    arr[6] = 2;
    arr[7] = 3;
    for (int i = 8; i <= MAX; i += 4) {
        arr[i] = (i - 4) + arr[i - 4];
        arr[i + 1] = arr[i] + i / 4 - 1;
        arr[i + 2] = arr[i] + i / 4 * 2 - 1;
        arr[i + 3] = arr[i] + i / 4 * 3 - 1;
    }

    printf("%lld", arr[N]);

    return 0;
}