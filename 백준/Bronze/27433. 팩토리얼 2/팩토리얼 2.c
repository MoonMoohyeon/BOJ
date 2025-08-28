#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll facto(int start) {
    ll ret = 1;
    while (start > 1) {
        ret *= start--;
    }

    return ret;
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    ll r = facto(n);
    printf("%lld", r);

    return 0;
}