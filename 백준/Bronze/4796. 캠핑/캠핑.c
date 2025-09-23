#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int L, P, V;

int main(int argc, char* argv[]) {
    int tc = 1;
    while (1) {
        int ans = 0;
        scanf("%d %d %d", &L, &P, &V);
        if (L == 0 && P == 0 && V == 0) break;
        while (V > 0) {
            if (V >= P) {
                ans += L;
                V -= P;
            }
            else {
                if (L >= V) {
                    ans += V;
                }
                else {
                    ans += L;
                }
                break;
            }
        }
        printf("Case %d: %d\n", tc++, ans);
    }

    return 0;
}