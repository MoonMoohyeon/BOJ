#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstring>
#include <queue>
#include <cmath>
#include <unordered_set>
using namespace std;

int N, M, ans;
char temp[1001][1001] = { 0, };
int board[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int isinbound(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) {
        return false;
    }
    return true;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (isinbound(ny, nx) && visited[ny][nx] == 0 && board[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = temp[i][j] - '0';
        }
    }

    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //        cout << board[i][j];
    //    }
    //    cout << endl;
    //}

    for (int i = 0; i < M; i++) {
        if(board[0][i] == 0) dfs(0, i);
    }

    //cout << endl;
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //        cout << visited[i][j];
    //    }
    //    cout << endl;
    //}

    for (int i = 0; i < M; i++) {
        if (visited[N - 1][i] == 1) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}