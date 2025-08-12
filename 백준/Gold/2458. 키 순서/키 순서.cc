#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N, M;
int graph[501][501];

void floyd() {
    // k: 거쳐가는 노드
    for (int k = 1; k <= N; k++) {
        // i: 출발 노드
        for (int i = 1; i <= N; i++) {
            // j: 도착 노드
            for (int j = 1; j <= N; j++) {
                // i에서 k를 거쳐 j로 가는 경로가 더 짧은 경우 갱신
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                graph[i][j] = 0; // 자기 자신으로 가는 경로는 0
            }
            else {
                graph[i][j] = INF; // 나머지는 무한대로 초기화
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        //graph[b][a] = 1;
    }

    floyd();

    //for (int i = 1; i <= N; i++) {
    //    for (int j = 1; j <= N; j++) {
    //        if (graph[i][j] == INF) {
    //            cout << "* ";
    //        }
    //        else {
    //            cout << graph[i][j] << " ";
    //        }
    //    }
    //    cout << endl;
    //}

    int ans, cnt;
    ans = cnt = 0;
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (graph[i][j] != INF) {
                cnt++;
            }
            if (graph[j][i] != INF) {
                cnt++;
            }
        }
        if (cnt >= N - 1) ans++;
    }

    cout << ans;

    return 0;
}