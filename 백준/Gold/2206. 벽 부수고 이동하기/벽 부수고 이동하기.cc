#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int N, M;
char map[1001][1001];
int dist[1001][1001][2]; // 해당 점까지의 거리, 벽을 부순 경우와 안 부순 경우

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<pair<int,int>,pair<int,int>>> q; // 벽을 부쉈는지, 현재 거리, y좌표, x좌표

int isinbound(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) return false;
    return true;
}

void BFS(int y, int x) {
    q.push({ {0, 1 }, { y,x }});
    dist[y][x][0] = 1;
    while (!q.empty()) {
        int k = q.front().first.first;
        int cdist = q.front().first.second;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (isinbound(ny, nx)) {
                if (map[ny][nx] == '0' && dist[ny][nx][k] == 0) { // 그냥 갈 수 있는 곳
                    q.push({ {k, cdist + 1 }, { ny,nx } });
                    dist[ny][nx][k] = cdist + 1;
                }
                else if (map[ny][nx] == '1' && k == 0 && dist[ny][nx][k] == 0) { // 벽인 곳, 벽을 하나 부숴야 갈 수 있음.
                    q.push({ {k + 1, cdist + 1 }, { ny,nx }});
                    dist[ny][nx][k + 1] = cdist + 1;
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    BFS(0, 0);
    
    //cout << endl;
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //        cout << dist[i][j][0];
    //    }
    //    cout << endl;
    //}

    //cout << endl;
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //        cout << dist[i][j][1];
    //    }
    //    cout << endl;
    //}


    int res1 = dist[N - 1][M - 1][0];
    int res2 = dist[N - 1][M - 1][1];

    //cout << res1 << " " << res2 << endl;

    if (res1 == 0 && res2 == 0) { // 도달 불가
        cout << "-1";
    }
    else if (res1 != 0 && res2 == 0) {
        cout << res1;
    }
    else if (res1 == 0 && res2 != 0) {
        cout << res2;
    }
    else if (res1 != 0 && res2 != 0) {
        cout << min(res1, res2);
    }

    return 0;
}