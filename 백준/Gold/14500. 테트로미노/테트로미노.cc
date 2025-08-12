#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int N, M;
int board[501][501];
int visited[501][501] = { 0, };
int sum, ans;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

bool isinbound(int y, int x) {
    if (x < 0 || y < 0 || x >= M || y >= N) return false;
    return true;
}

void ismax(int sum) {
    if (sum > ans) ans = sum;
}

void DFS(int y, int x, int sum, int cnt) {
    if (cnt == 4) {
        ismax(sum);
        return;
    }

    // 현재 위치에서 4방향 모두 탐색
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (isinbound(ny, nx) && visited[ny][nx] == 0) {
            visited[ny][nx] = 1;
            DFS(ny, nx, sum + board[ny][nx], cnt + 1);
            visited[ny][nx] = 0;
        }
    }
}

void cal(int y, int x) {
    int sum = 0;

    // ㅗ
    if (isinbound(y, x) && isinbound(y, x + 1) && isinbound(y, x + 2) && isinbound(y - 1, x + 1)) {
        sum = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y - 1][x + 1];
        ismax(sum);
    }

    // ㅜ
    if (isinbound(y, x) && isinbound(y, x + 1) && isinbound(y, x + 2) && isinbound(y + 1, x + 1)) {
        sum = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1];
        ismax(sum);
    }

    // ㅏ
    if (isinbound(y, x) && isinbound(y + 1, x) && isinbound(y + 2, x) && isinbound(y + 1, x + 1)) {
        sum = board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x + 1];
        ismax(sum);
    }

    // ㅓ
    if (isinbound(y, x) && isinbound(y + 1, x) && isinbound(y + 2, x) && isinbound(y + 1, x - 1)) {
        sum = board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x - 1];
        ismax(sum);
    }
}

int main(void) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    ans = sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 1;
            DFS(i, j, board[i][j], 1);
            visited[i][j] = 0;
            cal(i, j);
        }
    }

    cout << ans;

    return 0;
}