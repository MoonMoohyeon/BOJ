#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long

int arr[11];
int N;
int B, S;
double L;

int main(int argc, char* argv[]) {

    for (int i = 0; i < 11; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &N);

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d %lf %d", &B, &L, &S);

        if (L >= 2.0 && S >= 17) {
            ans += arr[B];
        }
    }

    printf("%d", ans);

    return 0;
}