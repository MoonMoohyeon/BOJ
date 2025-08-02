#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

vector<pair<int, int>> graph[10001];
int mark[10001] = { 0, };
priority_queue<pair<int, int>> pq;
int min_cost[10001];

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    for (int i = 1; i <= V; i++) {
        min_cost[i] = INT_MAX;
    }

    min_cost[1] = 0;
    pq.push({ 0, 1 });

    long long sum = 0;
    int cnt = 0;

    while (!pq.empty() && cnt < V) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (cost > min_cost[pos] || mark[pos]) continue;

        sum += cost;
        mark[pos] = 1;
        cnt++;

        for (auto& edge : graph[pos]) {
            int ncost = edge.first;
            int npos = edge.second;

            if (!mark[npos] && ncost < min_cost[npos]) {
                min_cost[npos] = ncost;
                pq.push({ -ncost, npos });
            }
        }
    }

    cout << sum;


    return 0;
}