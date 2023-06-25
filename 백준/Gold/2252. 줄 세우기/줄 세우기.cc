#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[32001];
int indegree[32001] = {0, };
int mark[32001] = {0, };
queue<int> q;

void topology(int node)
{
    for (auto j = graph[node].begin(); j != graph[node].end(); j++)
    {
        if (--indegree[*j] == 0 && mark[*j] == 0)
        {
            q.push(*j);
            mark[*j] = 1;
            topology(*j);
        }
    }
}

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
        if (indegree[i] == 0 && mark[i] == 0)
        {
            q.push(i);
            mark[i] = 1;
            topology(i);
        }
    }

    while (!q.empty())
    {
        printf("%d ", q.front());
        q.pop();
    }

    
    return 0;
}
