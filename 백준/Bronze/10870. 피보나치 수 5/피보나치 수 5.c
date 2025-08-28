#include <stdio.h>
#include <stdlib.h>
#define ll long long

int DP[21];

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);

    DP[0] = 0;
    DP[1] = 1;
    for (int i = 2; i <= n; ++i) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }
    printf("%d", DP[n]);

    return 0;
}