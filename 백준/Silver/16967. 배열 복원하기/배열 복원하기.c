#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int H, W, X, Y;
int A[301][301];
int B[601][601];

void printA() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    
    scanf("%d %d %d %d", &H, &W, &X, &Y);
    for (int i = 0; i < H + X; ++i) {
        for (int j = 0; j < W + Y; ++j) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < W; ++j) {
            A[i][j] = B[i][j];
        }
    }
    
    for (int i = X; i < H; ++i) {
        for (int j = 0; j < Y; ++j) {
            A[i][j] = B[i][j];
        }
    }
    
    for (int i = X; i < H; ++i) {
        for (int j = Y; j < W; ++j) {
            A[i][j] = B[i][j] - A[i - X][j - Y];
        }
    }

    printA();

    return 0;
}
