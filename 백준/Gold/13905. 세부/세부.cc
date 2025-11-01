#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct cmp {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { // 가중치, a 노드, b 노드
        if (a.first < b.first)
            return true;
        else
            return false;
    }
};
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

vector<pair<int, int>> graph[100001];
int mark[100001] = { 0, };

int main(void) {
    int V, E;
    int start, end;
    scanf("%d %d", &V, &E);
    scanf("%d %d", &start, &end);
    int a, b, c;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int cur = end;
    mark[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        pq.push(make_pair(graph[cur][i].second, make_pair(cur, graph[cur][i].first)));
    }

    int res = 1000001;
    while (!pq.empty()) {
        auto output = pq.top();
        pq.pop();

        int from = output.second.first;
        int to = output.second.second;
        int cost = output.first;

        if (mark[to] == 1)
            continue;

        if (cost < res) res = cost;

        cur = to;
        mark[cur] = 1;

        if (mark[start] == 1) break;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;

            if (mark[next] == 0) {
                pq.push(make_pair(next_cost, make_pair(cur, next)));
            }
        }
    }

    if (mark[start] == 0) {
        printf("0");
    }
    else {
        printf("%d", res);
    }

    return 0;
}