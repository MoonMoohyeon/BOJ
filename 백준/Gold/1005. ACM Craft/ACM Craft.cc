#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int T, N, M, W;
int buildtime[1001];
vector<int> graph[1001];
int indegree[1001];
int mark[1001];
int needtime[1001]; // DP
queue<pair<int, int>> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            cin >> buildtime[i];
            indegree[i] = 0;
            needtime[i] = 0;
            mark[i] = 0;
        }
        q = queue<pair<int, int>>();

        for (int i = 1; i <= N; i++) {
            graph[i].clear();
        }

        for (int i = 1; i <= M; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> W;

        // 큐로 다시 짜기
        for (int i = 1; i <= N; i++) {
            if (mark[i] == 0 && indegree[i] == 0) {
                needtime[i] = buildtime[i];
                q.push({ buildtime[i], i });
            }
        }

        while (!q.empty()) {
            int cost = q.front().first;
            int cur = q.front().second;
            q.pop();
            
            for (auto i = graph[cur].begin(); i != graph[cur].end(); i++) {
                needtime[*i] = max(needtime[*i], needtime[cur] + buildtime[*i]);
                if (--indegree[*i] == 0) {
                    q.push({ buildtime[*i], *i });
                }
            }
        }

        cout << needtime[W] << "\n";
    }
 
    return 0;
}