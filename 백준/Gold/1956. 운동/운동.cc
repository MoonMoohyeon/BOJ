#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10e8;
int N, M;
int graph[401][401];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        //graph[b][a] = c;
    }

    for (int i = 0; i < 401; i++) {
        for (int j = 0; j < 401; j++) {
            if (graph[i][j] == 0) {
                graph[i][j] = INF;
            }
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                //graph[k][i][j] = min(graph[k-1][i][j], graph[k-1][i][k] + graph[k-1][k][j]);
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    //cout << endl;
    //for (int i = 1; i <= N; i++) {
    //    for (int j = 1; j <= N; j++) {
    //        if (graph[i][j] == INF) cout << "* ";
    //        else cout << graph[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    /*
        모든 간선이 양수이므로 최소 비용 사이클은 무조건 노드 두 개를 잇는 경로여야 함.
    */
    
    int min = INF;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && graph[i][j] != INF && graph[j][i] != INF) {
                int cost = graph[i][j] + graph[j][i];
                if (cost < min) min = cost;
            }
        }
    }
    
    if (min == INF) cout << "-1";
    else cout << min;

    return 0;
}