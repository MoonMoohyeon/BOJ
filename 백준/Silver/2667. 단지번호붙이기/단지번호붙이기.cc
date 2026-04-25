#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

char graph[25][25];
int mark[25][25] = {{0, }};
queue<pair<int,int>> q;
vector<int> vec;
int N;

void BFS(int a, int b)
{
    q.push(make_pair(a, b));
    mark[a][b] = 1;
    int count = 0;
    while (!q.empty())
    {
        count++;
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i - 1 >= 0 && graph[i - 1][j] == '1' && mark[i - 1][j] == 0)
        {
            q.push(make_pair(i - 1, j));
            mark[i - 1][j] = 1;
        }
        if (i + 1 < N && graph[i + 1][j] == '1' && mark[i + 1][j] == 0)
        {
            q.push(make_pair(i + 1, j));
            mark[i + 1][j] = 1;
        }
        if (j - 1 >= 0 && graph[i][j - 1] == '1' && mark[i][j - 1] == 0)
        {
            q.push(make_pair(i, j - 1));
            mark[i][j - 1] = 1;
        }
        if (j + 1 < N && graph[i][j + 1] == '1' && mark[i][j + 1] == 0)
        {
            q.push(make_pair(i, j + 1));
            mark[i][j + 1] = 1;
        }
    }
    vec.push_back(count);
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
            scanf("%s", graph[i]);
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == '1' && mark[i][j] == 0)
            {
                BFS(i, j);
                count++;
            }
        }
    }

    printf("%d\n", count);
    sort(vec.begin(), vec.end());
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        printf("%d\n", *i);
    }

    return 0;
}