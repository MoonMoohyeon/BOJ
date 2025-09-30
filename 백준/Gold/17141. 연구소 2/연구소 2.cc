#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

int N, M;
int lab[50][50];
unordered_map<int, pair<int, int>> idx_to_coord;
int selected[10];
int mcnt = 0;
int ans = 10e8;

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int check() {
    int dist[50][50];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    int maxv = 0;
    for (int i = 0; i < mcnt; ++i) {
        if (selected[i]) {
            auto v = idx_to_coord[i];
            q.push({ v.first, v.second });
            dist[v.first][v.second] = 0;
        }
    }

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (lab[ny][nx] == 1) continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[cy][cx] + 1;
            q.push({ ny,nx });
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (lab[i][j] != 1) {
                if (dist[i][j] == -1) return 10e8;
                maxv = max(maxv, dist[i][j]);
            }
        }
    }

    return maxv;
}

void search(int start, int n) {
    if (n >= M) {
        int temp = check();
        ans = min(ans, temp);
        return;
    }

    for (int i = start; i < mcnt; ++i) {
        if (selected[i]) continue;
        selected[i] = 1;
        search(i + 1, n + 1);
        selected[i] = 0;
    }
}

int main(int argc, char* argv[]) {
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &lab[i][j]);
            if (lab[i][j] == 2) {
                idx_to_coord[mcnt++] = { i,j };
            }
        }
    }

    // 맵에 있는 2 중에서 M개를 고르는 모든 경우의 수에 대하여 완전탐색한다.

    search(0, 0);
    if (ans == 10e8) {
        printf("-1");
        return 0;
    }
    printf("%d", ans);

    return 0;
}
