#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 999999999;

int graph[101][101] = {{
    0,
}};

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, d;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                graph[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &d);
        if (d < graph[a][b])
            graph[a][b] = d;
    }

    for (int m = 1; m <= n; m++)
    {
        for (int s = 1; s <= n; s++)
        {
            for (int e = 1; e <= n; e++)
            {
                if (graph[s][e] > graph[s][m] + graph[m][e])
                {
                    graph[s][e] = graph[s][m] + graph[m][e];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
