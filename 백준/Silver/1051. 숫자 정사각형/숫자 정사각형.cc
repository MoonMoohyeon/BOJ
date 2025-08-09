#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
char tmb[51][51];
int board[51][51];
int ans = 0;

void calsize(int y, int x, int c) {
    int tmp = 0;
    for (int i = 0; i < 50; i++) {
        if (y + i >= N) return;
        if (x + i >= M) return;
        if (board[y][x] == board[y + i][x]) {
            if (board[y][x] == board[y][x + i]) {
                if (board[y][x] == board[y + i][x + i]) {
                    tmp = (i + 1) * (i + 1);
                    if (tmp > ans) ans = tmp;
                }
            }
        }
    }

    return;
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tmb[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = tmb[i][j] - '0';
        }
    }

    int t;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            calsize(i, j, board[i][j]);
        }
    }

    cout << ans;

    return 0;
}