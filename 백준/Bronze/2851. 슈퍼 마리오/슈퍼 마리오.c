#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N = 10;
int arr[101];
int psum[101];

int check(int num) {
    return abs(100 - num);
}

int main(int argc, char** argv) {
    
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &arr[i]);
    }

    psum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + arr[i];
    }

    //for (int i = 1; i <= N; ++i) {
    //    printf("%d ", psum[i]);
    //}

    int ans = 10e8;
    int cmp = 10e8;

    for (int i = 0; i <= N; ++i) {
        int tmp = check(psum[i]);
        if (tmp < cmp || (tmp == cmp && psum[i] > ans)) {
            cmp = tmp;
            ans = psum[i];
        }
            //printf("tmp : %d %d\n", cmp, psum[j] - psum[i]);
    }

    printf("%d", ans);


    return 0;
}