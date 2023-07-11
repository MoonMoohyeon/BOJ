#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[10001];

int dist[20001] = {
    0,
};

int main(void)
{
    int T;
    int N, M, C;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        memset(dist, 0, sizeof(dist));
        for (int i = 0; i < 10001; i++)
        {
            graph[i].clear();
        }
        scanf("%d %d %d", &N, &M, &C);
        int a, b, d;

        int start = C;
        //scanf("%d", &start);

        for (int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &a, &b, &d);
            //graph[a].push_back(make_pair(b, d));
            graph[b].push_back(make_pair(a, d));
        }

        for (int i = 1; i <= N; i++)
        {
            dist[i] = INF;
        }

        dist[start] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty())
        {
            auto cur = pq.top();
            int curdist = -cur.first;
            int curnode = cur.second;
            pq.pop();

            for (int i = 0; i < graph[curnode].size(); i++)
            {
                int nnode = graph[curnode][i].first;
                int ndist = curdist + graph[curnode][i].second;
                if (ndist < dist[nnode])
                {
                    dist[nnode] = ndist;
                    pq.push(make_pair(-ndist, nnode));
                }
            }

        }

        int cnt = 0;
        int time = 0;
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] != INF) cnt++;
            if (dist[i] > time && dist[i] != INF) time = dist[i];
        }

        printf("%d %d\n", cnt, time);
    }
    

    return 0;
}
