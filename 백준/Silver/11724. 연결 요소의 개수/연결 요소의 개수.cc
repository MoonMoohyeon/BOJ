#include <stdio.h>
#include <stdlib.h>
using namespace std;

int N, M;
int graph[1001][1001] = {{0, }};
int mark[1001] {0, };

void DFS(int start)
{
    mark[start] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (graph[start][i] == 1 && mark[i] == 0)
        {
            //printf("DFS%d in func\n", i);
            DFS(i);
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        graph[n][m] = 1;
        graph[m][n] = 1;
    }

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (mark[i] == 0)
        {
            //printf("DFS%d\n", i);
            DFS(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}