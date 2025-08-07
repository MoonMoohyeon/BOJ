#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstring>
using namespace std;

int board[20][20];
int N = 19;

// 좌표가 바둑판 범위 내에 있는지 확인하는 함수
bool isinbound(int y, int x) {
    if (y < 0 || x < 0 || x >= N || y >= N) {
        return false;
    }
    return true;
}

// (y, x)에서 시작하는 오목이 있는지 확인하는 함수
int check(int y, int x, int color) {
    int rcnt, ccnt, crcnt, clcnt;
    rcnt = ccnt = crcnt = clcnt = 0;

    // 1. 가로 (오른쪽 →) 확인
    for (int i = 0; i < 5; i++) {
        if (isinbound(y, x + i) && board[y][x + i] == color) rcnt++;
    }
    if (rcnt == 5) {
        // 육목(6알 이상)인지 확인: 시작점의 왼쪽 또는 끝점의 오른쪽에 같은 색 돌이 있으면 안 됨
        if (!((isinbound(y, x - 1) && board[y][x - 1] == color) ||
            (isinbound(y, x + 5) && board[y][x + 5] == color))) {
            return 1;
        }
    }

    // 2. 세로 (아래 ↓) 확인
    for (int i = 0; i < 5; i++) {
        if (isinbound(y + i, x) && board[y + i][x] == color) ccnt++;
    }
    if (ccnt == 5) {
        // 육목 확인: 시작점의 위쪽 또는 끝점의 아래쪽에 같은 색 돌이 있으면 안 됨
        if (!((isinbound(y - 1, x) && board[y - 1][x] == color) ||
            (isinbound(y + 5, x) && board[y + 5][x] == color))) {
            return 1;
        }
    }

    // 3. 대각선 (우하향 ↘, 우상향 ↗) 확인
    for (int i = 0; i < 5; i++) {
        if (isinbound(y + i, x + i) && board[y + i][x + i] == color) crcnt++; // 우하향
        if (isinbound(y - i, x + i) && board[y - i][x + i] == color) clcnt++; // 우상향
    }
    if (crcnt == 5) { // 우하향 대각선 ↘
        // 육목 확인: 시작점의 좌상단 또는 끝점의 우하단에 같은 색 돌이 있으면 안 됨
        if (!((isinbound(y - 1, x - 1) && board[y - 1][x - 1] == color) ||
            (isinbound(y + 5, x + 5) && board[y + 5][x + 5] == color))) {
            return 1;
        }
    }
    if (clcnt == 5) { // 우상향 대각선 ↗
        // 육목 확인: 시작점의 좌하단 또는 끝점의 우상단에 같은 색 돌이 있으면 안 됨
        if (!((isinbound(y + 1, x - 1) && board[y + 1][x - 1] == color) ||
            (isinbound(y - 5, x + 5) && board[y - 5][x + 5] == color))) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 바둑판 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 가장 왼쪽, 그다음 가장 위쪽 돌부터 탐색
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (board[i][j] != 0) {
                if (check(i, j, board[i][j])) {
                    cout << board[i][j] << "\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "0\n";
    return 0;
}
