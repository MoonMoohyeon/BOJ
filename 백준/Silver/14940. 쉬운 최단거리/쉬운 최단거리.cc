#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int map[1001][1001];
int res[1001][1001] = { {-1, } };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    pair<int,int> dst;
    queue<pair<int, int>> q;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            res[i][j] = -1;
        }
    }

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                dst.first = i;
                dst.second = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) res[i][j] = INT_MAX;
        }
    }

    q.push({ dst.first, dst.second });
    res[dst.first][dst.second] += 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first + 1 < n && map[cur.first + 1][cur.second] == 1 && res[cur.first + 1][cur.second] == -1 && res[cur.first][cur.second] != INT_MAX) {
            res[cur.first + 1][cur.second] = res[cur.first][cur.second] + 1;
            q.push({ cur.first + 1, cur.second });
        }
        if (cur.first - 1 >= 0 && map[cur.first - 1][cur.second] == 1 && res[cur.first - 1][cur.second] == -1 && res[cur.first][cur.second] != INT_MAX) {
            res[cur.first - 1][cur.second] = res[cur.first][cur.second] + 1;
            q.push({ cur.first - 1, cur.second });
        }
        if (cur.second + 1 < m && map[cur.first][cur.second + 1] == 1 && res[cur.first][cur.second + 1] == -1 && res[cur.first][cur.second] != INT_MAX) {
            res[cur.first][cur.second + 1] = res[cur.first][cur.second] + 1;
            q.push({ cur.first, cur.second + 1 });
        }
        if (cur.second - 1 >= 0 && map[cur.first][cur.second - 1] == 1 && res[cur.first][cur.second - 1] == -1 && res[cur.first][cur.second] != INT_MAX) {
            res[cur.first][cur.second - 1] = res[cur.first][cur.second] + 1;
            q.push({ cur.first, cur.second - 1 });
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == INT_MAX) cout << "0 ";
            else cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
