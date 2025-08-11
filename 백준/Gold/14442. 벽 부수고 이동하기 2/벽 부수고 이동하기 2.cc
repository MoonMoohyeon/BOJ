#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int y, x;
    int k, d;
};

int N, M, K;
char map[1001][1001];
int dist[1001][1001][11] = { 0, };
queue<Node> q;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

bool isinbound(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) {
        return false;
    }
    return true;
}

void BFS() {
    Node n;
    n.y = n.x = n.k = n.d = 0;
    n.d = 1;
    dist[n.y][n.x][n.k] = 1;
    q.push(n);

    while (!q.empty()) {
        int cy = q.front().y;
        int cx = q.front().x;
        int ck = q.front().k;
        int cd = q.front().d;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (isinbound(ny, nx)) {
                if (map[ny][nx] == '0' && dist[ny][nx][ck] == 0) { // 벽이 없는 경우
                    Node t;
                    t.y = ny;
                    t.x = nx;
                    t.k = ck;
                    t.d = cd + 1;
                    dist[ny][nx][ck] = cd + 1;
                    q.push(t);
                }
                else if (map[ny][nx] == '1' && dist[ny][nx][ck + 1] == 0 && ck < K) { // 벽을 뚫고 가야하는 경우
                    Node t;
                    t.y = ny;
                    t.x = nx;
                    t.k = ck + 1;
                    t.d = cd + 1;
                    dist[ny][nx][ck + 1] = cd + 1;
                    q.push(t);
                }
            }
        }
    }
}

int main(void) {

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    BFS();

    //cout << endl;
    //for (int k = 0; k <= K;k++) {
    //    for (int i = 0; i < N; i++) {
    //        for (int j = 0; j < M; j++) {
    //            cout << dist[i][j][k];
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    int mindist = INT_MAX;
    int flag = 0;
    for (int i = 0; i <= K; i++) {
        if (dist[N - 1][M - 1][i] != 0) {
            flag = 1;
            break;
        }
    }

    if (!flag) { // 도달 불가
        cout << "-1";
        return 0;
    }

    for (int i = 0; i <= K; i++) {
        if (dist[N - 1][M - 1][i] != 0 && dist[N - 1][M - 1][i] < mindist) {
            mindist = dist[N - 1][M - 1][i];
        }
    }

    cout << mindist;

    return 0;
}