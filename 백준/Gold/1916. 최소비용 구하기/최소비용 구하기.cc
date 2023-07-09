#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[100001];

int dist[100001] = {0};

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int a, b, d;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &d);
        graph[a].push_back(make_pair(b, d));
        // graph[b].push_back(make_pair(a, d));
    }

    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dist[start] = 0;

    priority_queue<pair<int, int>> pq; // 최단 거리, 노드

    pq.push({0, start});

    while (!pq.empty())
    {
        int curdist = -pq.top().first;
        int curnode = pq.top().second;
        pq.pop();

        if (dist[curnode] < curdist)
            continue;

        for (int i = 0; i < graph[curnode].size(); i++)
        {
            int nnode = graph[curnode][i].first;
            int ndist = curdist + graph[curnode][i].second;

            if (ndist < dist[nnode])
            {
                dist[nnode] = ndist;
                pq.push({-ndist, nnode});
            }
        }
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     printf("%d ", dist[i]);
    // }

    printf("%d\n", dist[end]);

    return 0;
}
