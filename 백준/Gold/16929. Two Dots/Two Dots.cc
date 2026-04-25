#include <iostream>
using namespace std;

char graph[51][51];
int check[51][51] = { {0,} };

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int sx, sy;

int N, M;

void DFS(int y, int x, int count)
{
	if (check[y][x] == 1) return;

	check[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (sy == ny && sx == nx && count >= 4)
		{
			printf("Yes");
			exit(0);
		}

		if (ny >= 0 && ny < N && nx >= 0 && nx < M)
		{
			if (graph[y][x] == graph[ny][nx] && check[ny][nx] == 0)
			{
				DFS(ny, nx, count + 1);
			}
		}
	}

	check[y][x] = 0;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", graph[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			sy = i;
			sx = j;
			DFS(i, j, 1);
		}
	}

	printf("No");

	
	return 0;
}

