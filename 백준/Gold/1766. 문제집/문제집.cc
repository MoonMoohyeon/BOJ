#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[32001];
int indegree[32001] = { 0, };
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
    int N, M;
    int a, b;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        printf("%d ", cur);
        for (auto j = graph[cur].begin(); j != graph[cur].end(); j++)
        {
            if (--indegree[*j] == 0)
            {
                pq.push(*j);
            }
        }
    }


    return 0;
}
