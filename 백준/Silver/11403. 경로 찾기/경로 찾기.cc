#include <iostream>
#include <algorithm>
using namespace std;

int graph[101][101] = {{
    0,
}};

int main(void)
{
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] != 1)
                graph[i][j] = 999;
        }
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
            if (graph[i][j] == 999)
                printf("0 ");
            else
                printf("1 ");
        }
        printf("\n");
    }

    return 0;
}
