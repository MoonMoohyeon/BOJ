#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> graph[50001];
int level[50001] = { 0, };
int parent[50001] = {0, };
queue<int> q;

void BFS(int prev, int next)
{
    level[next] = level[prev] + 1;
    parent[next] = prev;
    for (auto i = graph[next].begin(); i != graph[next].end(); i++)
    {
        if (level[*i] == 0)
        {
            q.push(*i);
            BFS(next, *i);
        }
    }
}

int main(void)
{
    int N, M;
    int x, y;
    int a, b;

    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    BFS(0, 1);
    /*for (int i = 1; i <= N; i++)
    {
        printf("%d = %d\n", i, level[i]);
    }
    printf("\n");
    for (int i = 1; i <= N; i++)
    {
        printf("%d = %d\n", i, parent[i]);
    }*/

    scanf("%d", &M);
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &a, &b);
        while (level[a] != level[b])
        {
            if (level[a] < level[b])
            {
                b = parent[b];
            }
            else
            {
                a = parent[a];
            }
        }
        while (a != b)
        {
            a = parent[a];
            b = parent[b];
        }

        printf("%d\n", a);
    }

    return 0;
}
