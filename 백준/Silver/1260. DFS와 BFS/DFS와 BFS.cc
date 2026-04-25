#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
vector<int> dorder;
vector<int> border;
queue<int> q;

int dmark[1001] = {
    0,
};
int bmark[1001] = {
    0,
};

void DFS(int n)
{
    if (dmark[n] != 0)
        return;

    dmark[n] = 1;
    dorder.push_back(n);
    for (auto i = graph[n].begin(); i != graph[n].end(); i++)
    {
        DFS(*i);
    }
}

void BFS(int n)
{
    q.push(n);
    bmark[n] = 1;
    border.push_back(n);

    while (!q.empty())
    {
        auto next = q.front();
        q.pop();
        for (auto i = graph[next].begin(); i != graph[next].end(); i++)
        {
            if (bmark[*i] == 0)
            {
                q.push(*i);
                border.push_back(*i);
                bmark[*i] = 1;
            }
        }
    }
}

int main(void)
{
    int N, M, V;
    int a, b;
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);
    BFS(V);

    for (auto i = dorder.begin(); i != dorder.end(); i++)
    {
        printf("%d ", *i);
    }
    printf("\n");
    for (auto i = border.begin(); i != border.end(); i++)
    {
        printf("%d ", *i);
    }

    return 0;
}
