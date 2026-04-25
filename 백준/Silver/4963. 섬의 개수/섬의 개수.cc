#include <iostream>
#include <queue>
using namespace std;

int graph[51][51];
int mark[51][51];
queue<pair<int, int>> q;

int w, h;

void BFS(int a, int b)
{
    q.push(make_pair(a, b));
    mark[a][b] = 1;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i - 1 >= 0 && graph[i - 1][j] == 1 && mark[i - 1][j] == 0)
        {
            q.push(make_pair(i - 1, j));
            mark[i - 1][j] = 1;
        }
        if (i + 1 < h && graph[i + 1][j] == 1 && mark[i + 1][j] == 0)
        {
            q.push(make_pair(i + 1, j));
            mark[i + 1][j] = 1;
        }
        if (j - 1 >= 0 && graph[i][j - 1] == 1 && mark[i][j - 1] == 0)
        {
            q.push(make_pair(i, j - 1));
            mark[i][j - 1] = 1;
        }
        if (j + 1 < w && graph[i][j + 1] == 1 && mark[i][j + 1] == 0)
        {
            q.push(make_pair(i, j + 1));
            mark[i][j + 1] = 1;
        }
        if (i - 1 >= 0 && j - 1 >= 0 && graph[i - 1][j - 1] == 1 && mark[i - 1][j - 1] == 0)
        {
            q.push(make_pair(i - 1, j - 1));
            mark[i - 1][j - 1] = 1;
        }
        if (i + 1 < h && j - 1 >= 0 && graph[i + 1][j - 1] == 1 && mark[i + 1][j - 1] == 0)
        {
            q.push(make_pair(i + 1, j - 1));
            mark[i + 1][j - 1] = 1;
        }
        if (i - 1 >= 0 && j + 1 < w && graph[i - 1][j + 1] == 1 && mark[i - 1][j + 1] == 0)
        {
            q.push(make_pair(i - 1, j + 1));
            mark[i - 1][j + 1] = 1;
        }
        if (i + 1 < h && j + 1 < w && graph[i + 1][j + 1] == 1 && mark[i + 1][j + 1] == 0)
        {
            q.push(make_pair(i + 1, j + 1));
            mark[i + 1][j + 1] = 1;
        }
    }
}

int main(void)
{
	int count;
	while (true)
	{
		scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;

        for (int i = 0; i < 51; i++)
        {
            for (int j = 0; j < 51; j++)
            {
                graph[i][j] = 0;
                mark[i][j] = 0;
            }
        }

        count = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &graph[i][j]);
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (graph[i][j] == 1 && mark[i][j] == 0)
				{
					BFS(i, j);
					count++;
				}
			}
		}

        printf("%d\n", count);
	}

	return 0;
}