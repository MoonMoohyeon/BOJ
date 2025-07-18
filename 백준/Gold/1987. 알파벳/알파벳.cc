#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

char board[21][21];
char visit[21][21] = { 0, };
//char alpha[21][21][128] = { 0, };
char alpha[26];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int R, C;
int maxv = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int checkBound(int i, int j) {
    if (i < 0 || j < 0 || i >= R || j >= C) return 0;
    return 1;
}

void DFS(int i, int j) {
    if (visit[i][j] > maxv) maxv = visit[i][j];
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (checkBound(nx, ny) && visit[nx][ny] <= (visit[i][j] - 1) && !alpha[board[nx][ny] - 'A']) {
            alpha[board[nx][ny] - 'A']++;
            visit[nx][ny] = visit[i][j] + 1;
            DFS(nx, ny);
            alpha[board[nx][ny] - 'A'] = 0;
            visit[nx][ny] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    alpha[board[0][0] - 'A']++;
    visit[0][0] = 1;
    DFS(0, 0);

    //for (int i = 0; i < R; i++) {
    //    for (int j = 0; j < C; j++) {
    //        printf("%d ", visit[i][j]);
    //    }
    //    printf("\n");
    //}

    printf("%d", maxv);

    return 0;
}
