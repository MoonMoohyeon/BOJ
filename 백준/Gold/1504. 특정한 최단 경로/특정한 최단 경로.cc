#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int N, M, K;
int a, b, c;
int u, v;
vector<pair<int,int>> graph[801];
int dist[801] = { 0, };
priority_queue<pair<int, int>> pq;
const int INF = INT_MAX;

int maxv = 0;
int maxnode = 0;

void init(void) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }
}

void dijkstra(int src) {
    init();
    dist[src] = 0;
    pq.push({ -0, src });
    
    while (!pq.empty()) {
        int pos = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (cost > dist[pos]) continue;

        for (auto i = graph[pos].begin(); i != graph[pos].end(); i++) {
            int npos = i->second;
            int ncost = i->first + cost;

            if (ncost < dist[npos]) {
                dist[npos] = ncost;
                pq.push({ -ncost, npos });
            }
        }
    }

    //for (int i = 1; i <= N; i++) {
    //    cout << dist[i] << " ";
    //}
    //cout << endl;
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }
    cin >> u >> v;
    
    // 1 -> u -> v -> d
    // 1 -> v -> u -> d

    dijkstra(1);
    int dist_1_to_u = dist[u];
    int dist_1_to_v = dist[v];

    dijkstra(u);
    int dist_u_to_v = dist[v];
    int dist_u_to_N = dist[N];

    dijkstra(v);
    int dist_v_to_N = dist[N];

    long long route1 = -1;
    if (dist_1_to_u != INF && dist_u_to_v != INF && dist_v_to_N != INF) {
        route1 = (long long)dist_1_to_u + dist_u_to_v + dist_v_to_N;
    }

    long long route2 = -1;
    if (dist_1_to_v != INF && dist_u_to_v != INF && dist_u_to_N != INF) {
        route2 = (long long)dist_1_to_v + dist_u_to_v + dist_u_to_N;
    }

    long long final_dist = -1;
    if (route1 != -1 && route2 != -1) {
        final_dist = min(route1, route2);
    }
    else if (route1 != -1) {
        final_dist = route1;
    }
    else if (route2 != -1) {
        final_dist = route2;
    }

    cout << final_dist << "\n";

    return 0;
}