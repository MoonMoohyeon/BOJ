#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct cmp {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) // 가중치, a 노드, b 노드
    {
        if (a.first > b.first)
            return true;
        else
            return false;
    }
};
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

vector<pair<int, int>> graph[10001];
int mark[10001] = { 0, };

int main(void)
{
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);
    int a, b, c;
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int cur = 1;
    mark[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        pq.push(make_pair(graph[cur][i].second, make_pair(cur, graph[cur][i].first)));
    }

    int res = 0;
    while (!pq.empty())
    {
        auto output = pq.top();
        pq.pop();
        if (mark[output.second.first] == 1 && mark[output.second.second])
            continue;
        res += output.first;
        cur = output.second.second;
        mark[cur] = 1;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int a = graph[cur][i].second;
            int b = cur;
            int c = graph[cur][i].first;
            auto p = make_pair(b, c);
            auto z = make_pair(a, p);
            pq.push(z);
        }
    }

    printf("%d", res);

    return 0;
}