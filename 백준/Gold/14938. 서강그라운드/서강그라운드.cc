#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int N, M, R;
int item[101];
//vector<pair<int, int>> graph[101];
//int dist[101];
//priority_queue<pair<int, int>> pq;
int graph[101][101] = { 0, };
const int INF = 10e8;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        cin >> item[i];
    }
    for (int i = 0; i < R; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] == 0) {
                graph[i][j] = INF;
            }
            if (i == j) graph[i][j] = 0;
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                //graph[k][i][j] = min(graph[k - 1][i][j], graph[k - 1][i][k] + graph[k - 1][k][j]);
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int ans, sum;
    ans = sum = 0;
    //for (int i = 1; i <= N; i++) {
    //    for (int j = 1; j <= N; j++) {
    //        cout << graph[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    for (int i = 1; i <= N; i++) {
        sum = 0;
        for (int j = 1; j <= N; j++) {
            //cout << "cur : " << i << " ";
            if (graph[i][j] <= M) {
                //cout << "sum + " << item[j] << " ";
                sum += item[j];
            }
        }
        if (sum > ans) ans = sum;
    }
    cout << ans;

    return 0;
}