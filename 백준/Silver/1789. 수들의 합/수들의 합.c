#include <stdio.h>

int main() {

    long long S;
    long long res = 0;
    long long cnt = 0;
    long long i = 1;
    scanf("%lld", &S);
    
    while (1) {
        res += i;
        cnt++;
        i++;
        if (res > S) break;
    }

    printf("%lld", --cnt);
    
    return 0;
}
