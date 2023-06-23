#include <iostream>
#include <string.h>
using namespace std;

int mark[51][51] = {{0, }};
int graph[51][51] = {{0, }};
int M, N, K;

void DFS(int x, int y)
{
	mark[x][y] = 1;
	if (x + 1 < N && graph[x + 1][y] == 1 && mark[x + 1][y] == 0)
	{
		DFS(x + 1, y);
	}
	if (y + 1 < M && graph[x][y + 1] == 1 && mark[x][y + 1] == 0)
	{
		DFS(x, y + 1);
	}
	if (x - 1 >= 0 && graph[x - 1][y] == 1 && mark[x - 1][y] == 0)
	{
		DFS(x - 1, y);
	}
	if (y - 1 >= 0 && graph[x][y - 1] == 1 && mark[x][y - 1] == 0)
	{
		DFS(x, y - 1);
	}
}

int main(void)
{
	int T;
	int x, y;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int count = 0;
		scanf("%d %d %d", &M, &N, &K);

		memset(mark, 0, sizeof(mark));
		memset(graph, 0, sizeof(graph));

		for (int j = 0; j < K; j++)
		{
			scanf("%d %d", &x, &y);
			graph[y][x] = 1;
		}
		
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (graph[j][k] == 1 && mark[j][k] == 0)
				{
					count++;
					DFS(j, k);
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

