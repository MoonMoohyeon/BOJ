#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> graph[20001];
int mark[20001] = { 0, };

int blue = 0;
int red = 0;

void DFS(int prev, int next)
{
    if (mark[next] != 0) return;
    else if (mark[prev] == 1)
    {
        mark[next] = 2;
        red++;
    }
    else if (mark[prev] == 2)
    {
        mark[next] = 1;
        blue++;
    }
    //printf("prev = %d next = %d mark[prev] = %d\n", prev, next, mark[prev]);
    for (auto i = graph[next].begin(); i != graph[next].end(); i++)
    {
        DFS(next, *i);
    }
}

int main(void)
{
    int n, s;
    int v;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s);
        for (int j = 0; j < s; j++)
        {
            scanf("%d", &v);
            graph[i].push_back(v);   
            graph[v].push_back(i);
        }
    }

    /*printf("graph\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d = ", i);
        for (auto j = graph[i].begin(); j != graph[i].end(); j++)
        {
            printf("%d ", *j);
        }
        printf("\n");
    }*/

    mark[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            DFS(0, i);
        }
    }

    printf("%d\n", blue);
    for (int i = 1; i <= n; i++)
    {
        if(mark[i] == 1)
            printf("%d ", i);
    }

    printf("\n%d\n", red);
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 2)
            printf("%d ", i);
    }

    return 0;
}
