#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

char graph[101][102];
int mark[101][102] = { {0, } };
queue<pair<int, int>> q;
int N, M;

void BFS(int a, int b)
{
    q.push(make_pair(a, b));
    mark[a][b] = 1;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i - 1 >= 0 && graph[i - 1][j] == '1' && mark[i - 1][j] == 0)
        {
            q.push(make_pair(i - 1, j));
            mark[i - 1][j] = mark[i][j] + 1;
        }
        if (i + 1 < N && graph[i + 1][j] == '1' && mark[i + 1][j] == 0)
        {
            q.push(make_pair(i + 1, j));
            mark[i + 1][j] = mark[i][j] + 1;
        }
        if (j - 1 >= 0 && graph[i][j - 1] == '1' && mark[i][j - 1] == 0)
        {
            q.push(make_pair(i, j - 1));
            mark[i][j - 1] = mark[i][j] + 1;
        }
        if (j + 1 < M && graph[i][j + 1] == '1' && mark[i][j + 1] == 0)
        {
            q.push(make_pair(i, j + 1));
            mark[i][j + 1] = mark[i][j] + 1;
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", graph[i]);
    }

    BFS(0, 0);

    printf("%d\n", mark[N-1][M-1]);

    return 0;
}