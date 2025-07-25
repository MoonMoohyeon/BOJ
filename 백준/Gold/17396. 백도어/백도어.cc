#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int N, M;
int sight[100001];
vector<pair<long,long>> graph[100001];
priority_queue<pair<long, long>> pq;
long dist[100001] = { 0, };


int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> sight[i];
    }
    int a, b, t;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        //if (b != N - 1 && sight[b] == 1) continue;
        graph[a].push_back({ t,b });
        graph[b].push_back({ t,a });
    }

    for (int i = 0; i < 100001; i++) dist[i] = LONG_MAX;

    dist[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        auto cur = pq.top();
        long pos = cur.second;
        long cost = -cur.first;
        pq.pop();
        if (cost > dist[pos]) continue;
        if (sight[pos] == 1 && pos != N - 1) continue;

        for (auto i = graph[pos].begin(); i != graph[pos].end(); i++) {
            long npos = i->second;
            long ncost = i->first + cost;
            if (sight[npos] == 1 && npos != N - 1) continue;

            if (ncost < dist[npos]) {
                dist[npos] = ncost;
                pq.push({ -ncost, npos });
            }
        }
    }

    //for (int i = 0; i < N; i++) {
    //    cout << dist[i] << " ";
    //}

    dist[N - 1] == LONG_MAX ? cout << "-1" : cout << dist[N - 1];

    return 0;
}