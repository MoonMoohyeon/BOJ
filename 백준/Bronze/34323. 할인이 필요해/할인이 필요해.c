#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long

ll N, M, S;

int main(int argc, char** argv) {
    
    scanf("%lld %lld %lld", &N, &M, &S);
    ll discount = (S * (100 - N) * (M + 1)) / 100;
    ll plusone = S * M;

    //printf("%lld %lld\n", discount, plusone);
    if (discount < plusone) printf("%lld\n", discount);
    else printf("%lld\n", plusone);

    return 0;
}
