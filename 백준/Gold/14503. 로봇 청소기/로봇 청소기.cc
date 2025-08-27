#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int sy, sx, sdir;
int map[51][51];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

enum DIR {
    NORTH,
    SOUTH,
    WEST,
    EAST
};

struct state {
    int y, x, dir;
};

int isinbound(int y, int x) {
    return x >= 0 && y >= 0 && x < M && y < N;
}

int simulation(int y, int x, int dir) {
    int cy = y;
    int cx = x;
    int cdir = dir; // 0 북 1 동 2 남 3 서
    int cnt = 0; // 북 -> 서 -> 남 -> 동 -> 북
    while (true) {
        if (map[cy][cx] == 0) {
            cnt++;
            map[cy][cx] = 2;
        }

        int flag = 0;
        for (int i = 0; i < 4; i++) {
            int ndir = cdir - 1;
            if (ndir < 0) ndir = 3;

            int ny = cy + dy[ndir];
            int nx = cx + dx[ndir];
            cdir = ndir;
            
            if (isinbound(ny, nx) && map[ny][nx] == 0) {
                cy = ny;
                cx = nx;
                flag = 1;
                break;
            }
        }

        if (flag) { // 주변에 청소할 공간이 있음.
            continue;
        }
        else { // 후진해야 함.
            int ndir = (cdir + 2) % 4;
            int by = cy + dy[ndir];
            int bx = cx + dx[ndir];

            if (!isinbound(by, bx) || map[by][bx] == 1) break;

            cy = by;
            cx = bx;
        }
    }

    return cnt;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    cin >> sy >> sx >> sdir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    cout << simulation(sy, sx, sdir);

    return 0;
}