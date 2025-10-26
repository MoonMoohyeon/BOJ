#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int N, M;
int S, T;
vector<pair<int, int>> graph[5001];
int mark[5001] = { false, };
priority_queue<pair<int, int>> pq; // weight, to

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    for (int i = 1; i <= N; i++) {
        mark[i] = INT_MAX;
    }

    cin >> S >> T;

    mark[S] = 0;
    pq.push({ -0, S });

    while (!pq.empty()) {
        auto cur = pq.top();
        int cost = -cur.first;
        int pos = cur.second;
        pq.pop();

        if (pos == T) break; // 도착
        if (cost > mark[pos]) continue;

        for (auto i = graph[pos].begin(); i < graph[pos].end(); i++) {
            int ncost = i->first + cost;
            int npos = i->second;
            if (ncost < mark[npos]) {
                mark[npos] = ncost;
                pq.push({ -ncost, npos });
            }

        }
    }

    /*for (int i = 1; i <= N; i++) {
        cout << mark[i] << " ";
    }*/
    cout << mark[T];


    return 0;
}