#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> graph[20001];
int mark[20001] = {0, };
int check[20001] = {0, };

int flag = 0;

void DFS(int prev ,int next)
{
    if (mark[prev] == mark[next]) {
        flag = 1;
        return;
    }
    if (mark[next] != 0) return;
    else if (mark[prev] == 1)
    {
        mark[next] = 2;
    }
    else if (mark[prev] == 2) 
    {
        mark[next] = 1;
    }
    for (auto i = graph[next].begin(); i != graph[next].end(); i++)
    {
        DFS(next, *i);
    }
}

int main(void)
{
    int K;
    int V, E;
    int u, v;
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        flag = 0;
        memset(mark, 0, sizeof(int) * 20001);
        memset(check, 0, sizeof(int) * 20001);
        for (int v = 0; v < 20001; v++)
        {
            graph[v].clear();
        }

        scanf("%d %d", &V, &E);
        for (int j = 0; j < E; j++)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        mark[0] = 1;
        for (int n = 1; n <= V; n++)
        {
            if (mark[n] == 0)
            {
                DFS(0, n);
            }
        }
        
        if (flag == 1) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
