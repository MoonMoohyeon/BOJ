#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

int main(int argc, char* argv[]) {
    scanf("%d %d", &N);

    if (N % 2 == 1) {
        printf("Soomin");
        return 0;
    }
    else {
        printf("Song");
    }

    return 0;
}
