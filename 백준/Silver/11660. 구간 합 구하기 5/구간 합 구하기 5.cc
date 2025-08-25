#include <iostream>
#include <algorithm>
using namespace std;

int table[1025][1025] = {{0, }};
int psum[1025][1025] = {{0, }};

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &table[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] + table[i - 1][j - 1] - psum[i - 1][j - 1];
		}
	}

	/*printf("\n");
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			printf("%d ", psum[i][j]);
		}
		printf("\n");
	}*/

	int x1, x2, y1, y2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1]);
	}

	return 0;
}
