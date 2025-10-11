#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N;
string map[51];
int dist[51][51];

struct pos {
    int cost, y, x;

    bool operator<(const pos &right) const {
        return cost > right.cost;
    }
};

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

priority_queue<pos> q;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> map[i];
        for (int j = 0; j < N; ++j) {
            dist[i][j] = -1;
        }
    }

    q.push({ 0,0,0 });
    dist[0][0] = 0;

    while (!q.empty()) {
        pos cur = q.top();
        q.pop();

        int cy = cur.y;
        int cx = cur.x;
        int cc = cur.cost;

        if (dist[cy][cx] != -1 && cc > dist[cy][cx]) continue;

        for (int i = 0; i < 4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
            
            int nc = cc;
            if (map[ny][nx] == '0') nc++;

            if (dist[ny][nx] == -1 || nc < dist[ny][nx]) {
                dist[ny][nx] = nc;
                q.push({ nc, ny, nx });
            }
        }
    }

    cout << dist[N - 1][N - 1];

    return 0;
}