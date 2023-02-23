#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    int** graph;
    graph = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
        graph[i] = (int*)malloc(sizeof(int) * M);

    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &temp);
            graph[i][j] = temp;
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    int flag = 0;
    pair<int, int> up, down, left, right;

    while (1)
    {
        if (q.empty())
            break;

        flag = 0;
        int uf = 0, df = 0, lf = 0, rf = 0;
        auto out = q.front();
        int ox = out.first;
        int oy = out.second;
        q.pop();
        if (out.first - 1 >= 0 && out.first - 1 < N && out.second >= 0 && out.second < M)
        {
            if (graph[out.first - 1][out.second] == 0)
            {
                graph[out.first - 1][out.second] = graph[ox][oy] + 1;
                up = make_pair(out.first - 1, out.second);
                flag = 1;
                uf = 1;
            }
        }
        if (out.first >= 0 && out.first < N && out.second - 1 >= 0 && out.second - 1 < M)
        {
            if (graph[out.first][out.second - 1] == 0)
            {
                graph[out.first][out.second - 1] = graph[ox][oy] + 1;
                left = make_pair(out.first, out.second - 1);
                flag = 1;
                lf = 1;
            }
        }
        if (out.first + 1 >= 0 && out.first + 1 < N && out.second >= 0 && out.second < M)
        {
            if (graph[out.first + 1][out.second] == 0)
            {
                graph[out.first + 1][out.second] = graph[ox][oy] + 1;
                down = make_pair(out.first + 1, out.second);
                flag = 1;
                df = 1;
            }
        }
        if (out.first >= 0 && out.first < N && out.second + 1 >= 0 && out.second + 1 < M)
        {
            if (graph[out.first][out.second + 1] == 0)
            {
                graph[out.first][out.second + 1] = graph[ox][oy] + 1;
                right = make_pair(out.first, out.second + 1);
                flag = 1;
                rf = 1;
            }
        }

        if (uf) q.push(up);
        if (df) q.push(down);
        if (lf) q.push(left);
        if (rf) q.push(right);
    }

    int max = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] > max && max != 0)
                max = graph[i][j];
            if (graph[i][j] == 0) max = 0;
        }
    }

    printf("%d", --max);

    return 0;
}
