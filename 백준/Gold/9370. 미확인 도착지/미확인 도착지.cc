#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

const int INF = 10e8;

int N, M, K;
int S, G, H;
vector<pair<int,int>> graph[2001];
vector<int> candidates;
int distS[2001] = { 0, };
int distG[2001] = { 0, };
int distH[2001] = { 0, };
vector<int> ans;

void init() {
    ans.clear();
    candidates.clear();
    for (int i = 0; i < 2001; ++i) {
        graph[i].clear();
    }
}

void input() {
    cin >> N >> M >> K;
    cin >> S >> G >> H;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    for (int i = 0; i < K; ++i) {
        int c;
        cin >> c;
        candidates.push_back(c);
    }
}

int dijkstra(int src, int dst) {
    int dist[2001] = { 0, };
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 2001; ++i) {
        dist[i] = INF;
    }

    dist[src] = 0;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (cost > dist[pos]) continue;

        for (auto& edge : graph[pos]) {
            int ncost = edge.first + cost;
            int npos = edge.second;

            if (ncost < dist[npos]) {
                dist[npos] = ncost;
                pq.push({ -ncost, npos });
            }
        }
    }

    return dist[dst];
}

void dijkstraALL(int src, int* dist) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 2001; ++i) {
        dist[i] = INF;
    }

    dist[src] = 0;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (cost > dist[pos]) continue;

        for (auto& edge : graph[pos]) {
            int ncost = edge.first + cost;
            int npos = edge.second;

            if (ncost < dist[npos]) {
                dist[npos] = ncost;
                pq.push({ -ncost, npos });
            }
        }
    }

    return;
}

void solution() {
    int StoG = dijkstra(S, G);
    int StoH = dijkstra(S, H);
    int GtoH = dijkstra(G, H);

    dijkstraALL(S, distS);
    dijkstraALL(G, distG);
    dijkstraALL(H, distH);

    // StoG + GtoH + H to All
    // StoH + GtoH + G to All
    // S to ALL
    // 값이 같으면 후보지

    for (int i = 0; i < candidates.size(); i++) {
        int cand = candidates[i];

        if (StoG + GtoH + distH[cand] == distS[cand]) {
            ans.push_back(cand);
        }
        if (StoH + GtoH + distG[cand] == distS[cand]) {
            ans.push_back(cand);
        }
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        init();
        input();
        solution();

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}