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

vector<pair<int, int>> graph[1001];
int mark[1001] = { 0, };

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            scanf("%d", &temp);
            if (i == j) continue;
            graph[i].push_back({ j, temp });
        }
    }

    int cur = 1;
    mark[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        pq.push(make_pair(graph[cur][i].second, make_pair(cur, graph[cur][i].first)));
    }

    long long res = 0;
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

    printf("%lld\n", res);

    return 0;
}