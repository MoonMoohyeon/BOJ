#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[100001];
priority_queue<pair<int, pair<int, int>>> pq;
int dist[100001] = {0, };
int prv[100001];
int cnt = 1;
stack<int> s;

int main(void)
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    int a, b, w;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        graph[a].push_back(make_pair(w, b)); // 가중치, 다음 노드
        // graph[b].push_back(make_pair(a, d));
    }

    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
    }

    int start, end;
    scanf("%d %d", &start, &end);

    int cur = start;
	dist[cur] = 0; // 첫번째 노드 방문
	for (int i = 0; i < graph[cur].size(); i++) // 첫번째 노드로부터 다른 노드까지의 거리를 큐에 넣는다.
	{
        a = cur;
        b = graph[cur][i].second;
        w = graph[cur][i].first;
        pq.push({-w, {a, b}}); // 가중치, 이전노드, 다음노드
	}

    while (!pq.empty())
    {
        int curdist = -pq.top().first;
        int curnode = pq.top().second.second;
        int prevnode = pq.top().second.first;
        pq.pop();

        if (dist[curnode] < INF)
            continue;

        dist[curnode] = curdist;
        prv[curnode] = prevnode;
        for (int i = 0; i < graph[curnode].size(); i++)
        {
            int nnode = graph[curnode][i].second;
            int ndist = curdist + graph[curnode][i].first;
            pq.push({-ndist, {curnode, nnode}});
        }
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     printf("dist %d ", dist[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= N; i++)
    // {
    //     printf("prv = %d ", prv[i]);
    // }
    // printf("\n");

    printf("%d\n", dist[end]);
    int pos = end;
    s.push(pos);
    while(pos != start)
    {
        pos = prv[pos];
        // printf("pos = %d\n", pos);
        s.push(pos);
        cnt++;
    }
    printf("%d\n", cnt);

    while(!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}
