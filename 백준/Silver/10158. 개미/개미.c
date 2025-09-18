#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int W, H, P, Q, T;

int main(int argc, char* argv[]) {
    scanf("%d %d", &W, &H);
    scanf("%d %d", &P, &Q);
    scanf("%d", &T);

    int current_x = (P + T) % (2 * W);
    // 좌표가 W보다 크면 돌아오는 중
    if (current_x > W) {
        P = (2 * W) - current_x;
    }
    else {
        P = current_x; // W보다 작으면 벽에 부딪히기 전
    }

    int current_y = (Q + T) % (2 * H);
    if (current_y > H) {
        Q = (2 * H) - current_y;
    }
    else {
        Q = current_y;
    }

    printf("%d %d\n", P, Q);
    return 0;
}