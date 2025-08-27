#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

const int INF = 10e8;
int N, M, K;
int src, dst;
vector<pair<int, int>> graph[10001];
vector<int> path;
vector<int> edges;

int prim(int src, int dst) {
    int visited[10001];
    priority_queue<pair<int, int>> pq;

    int edgecnt = 0;
    int mstcost = 0;
    int maxweight = 0;
    vector<int> parent(10001);
    for (int i = 0; i <= N; ++i) {
        visited[i] = 0;
        parent[i] = -1;
    }

    visited[src] = 0;
    pq.push({ 0, src });
    while (!pq.empty()) {
        int cost = pq.top().first;
        int pos = pq.top().second;
        edges.push_back(cost);
        pq.pop();
        if (visited[pos] != 0) continue;
        visited[pos] = 1;
        mstcost += cost;
        edgecnt++;

        for (auto& edge : graph[pos]) {
            int ncost = edge.first;
            int npos = edge.second;

            if (visited[npos] != 0) continue;
            pq.push({ ncost, npos });
            parent[npos] = pos;
        }
        if (pos == dst) break;
    }

    //cout << "cost : " << mstcost << "\n";

    for (int i = dst; i != -1; i = parent[i]) {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());
    //cout << "path : ";
    //for (int i = 0; i < path.size(); ++i) {
    //    cout << path[i] << " ";
    //}
    //cout << "\n";
    return maxweight;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    cin >> src >> dst;

    prim(src, dst);

    int weight = 10e8;
    for (auto& e : edges) {
        if (e != 0) {
            if (e < weight) weight = e;
        }
        //cout << e << " ";
    }

    cout << weight;
    //for (int i = 0; i < path.size() - 1; ++i) {
    //    int v = path[i];
    //    int u = path[i + 1];
    //    for (int i = 0; i < graph[v].size(); i++) {
    //        if (graph[v][i].first == u) {
    //            if (graph[v][i].first < weight) {
    //                weight = graph[v][i].first;
    //            }
    //        }
    //    }
    //}

    //cout << weight;

    return 0;
}