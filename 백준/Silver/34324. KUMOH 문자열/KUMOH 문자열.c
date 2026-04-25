#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N;
char map[1001][1001];
char KUMHO[] = "KUMOH";

int countKUMHO(char* text, int len) {
    int count = 0;
    if (len < 5) return 0;
    for (int i = 0; i <= len - 5; ++i) {
        if (strncmp(text + i, KUMHO, 5) == 0) { // 금호 찾음
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", map[i]);
    }

    //for (int i = 0; i < N; ++i) {
    //    for (int j = 0; j < N; ++j) {
    //        printf("%c", map[i][j]);
    //    }
    //    printf("\n");
    //}

    int totalCnt = 0;
    char diagonalStr[2001];

    for (int start_i = 0; start_i < N; ++start_i) {
        int strIdx = 0;
        int i = start_i;
        int j = 0;

        while (i >= 0 && j < 1000) {
            if (j < strlen(map[i])) { // 문자열 범위 내에 있을 때
                diagonalStr[strIdx++] = map[i][j];
            }
            i--;
            j++;
        }
        diagonalStr[strIdx] = '\0';

        // 정방향
        int forwardCount = countKUMHO(diagonalStr, strIdx);

        // 역방향
        int backwardCount = 0;
        if (strIdx >= 5) {
            for (int k = strIdx - 1; k >= 4; --k) {
                if (diagonalStr[k] == 'K' && diagonalStr[k - 1] == 'U' &&
                    diagonalStr[k - 2] == 'M' && diagonalStr[k - 3] == 'O' &&
                    diagonalStr[k - 4] == 'H') {
                    backwardCount++;
                }
            }
        }

        if (forwardCount > backwardCount) totalCnt += forwardCount;
        else totalCnt += backwardCount;
    }

    for (int start_j = 1; start_j < 1000; ++start_j) {
        int strIdx = 0;
        int i = N - 1; // 마지막 행에서 시작
        int j = start_j;

        while (i >= 0 && j < 1000) {
            if (j < strlen(map[i])) {
                diagonalStr[strIdx++] = map[i][j];
            }
            i--;
            j++;
        }
        diagonalStr[strIdx] = '\0';

        int forwardCount = countKUMHO(diagonalStr, strIdx);
        int backwardCount = 0;
        if (strIdx >= 5) {
            for (int k = strIdx - 1; k >= 4; --k) {
                if (diagonalStr[k] == 'K' && diagonalStr[k - 1] == 'U' &&
                    diagonalStr[k - 2] == 'M' && diagonalStr[k - 3] == 'O' &&
                    diagonalStr[k - 4] == 'H') {
                    backwardCount++;
                }
            }
        }

        if (forwardCount > backwardCount) totalCnt += forwardCount;
        else totalCnt += backwardCount;
    }

    printf("%d", totalCnt);

    return 0;
}