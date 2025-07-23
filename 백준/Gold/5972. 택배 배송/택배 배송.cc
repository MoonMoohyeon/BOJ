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
vector<pair<int,int>> graph[50001];
int mark[50001] = { false, };
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

    mark[1] = 0;
    pq.push({ -0, 1 });

    while (!pq.empty()) {
        auto cur = pq.top();
        int cost = -cur.first;
        int pos = cur.second;
        pq.pop();

        //cout << "test = " << pos << " " << cost << "\n";

        if (cost > mark[pos]) continue;

        for (auto i = graph[pos].begin(); i < graph[pos].end(); i++) {
            int ncost = i->first + cost;
            int npos = i->second;
            //cout << "next = " << npos << " " << ncost << "\n";
            if (ncost < mark[npos]) {
                mark[npos] = ncost;
                pq.push({ -ncost, npos });
            }
        }
    }

    /*for (int i = 1; i <= N; i++) {
        cout << mark[i] << " ";
    }*/
    cout << mark[N];


    return 0;
}