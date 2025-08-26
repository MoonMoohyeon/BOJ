#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int N;
int map[65][65];
int visited[65][65];

int isinbound(int y, int x) {
    return y >= 0 && x >= 0 && y < N && x < N;
}

int dfs(int y, int x) {
    if (y == N - 1 && x == N - 1) {
        visited[y][x] = 1;
        return 1;
    }
    if (visited[y][x]) {
        return 0;
    }
    if (!isinbound(y, x)) {
        return 0;
    }

    visited[y][x] = 1;

    int rightx = x + map[y][x];
    int righty = y;

    int downx = x;
    int downy = y + map[y][x];

    if (isinbound(righty, rightx) && visited[righty][rightx] == 0) {
        dfs(righty, rightx);
    }

    if (isinbound(downy, downx) && visited[downy][downx] == 0) {
        dfs(downy, downx);
    }

    return 0;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, 0);

    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        cout << visited[i][j];
    //    }
    //    cout << "\n";
    //}

    if (visited[N - 1][N - 1] == 1) {
        cout << "HaruHaru";
    }
    else {
        cout << "Hing";
    }

    return 0;
}