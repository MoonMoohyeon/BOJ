#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long

void can(int cnt) {
    if (cnt == 0) {
        printf("-");
        return;
    }

    /*
        N = 0 -> -
        F(N + 1) = F(N) + " " * 3^N-1 + F(N)
    */

    can(cnt - 1);
    int blank = pow(3, cnt - 1);
    for (int i = 0; i < blank; ++i) printf(" ");
    can(cnt - 1);
}

int main(int argc, char** argv) {
    int n;
    while (1) {
        int sret = scanf("%d", &n);
        if (sret == EOF) break;
        can(n);
        printf("\n");
    }

    return 0;
}