#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int DP[30][30];

	int n, m;
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &n, &m);

		memset(DP, 0, sizeof(DP));

		for (int j = 1; j <= m; j++)
		{
			DP[1][j] = j;
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int k = 1; k < j; k++)
				{
					DP[i][j] += DP[i - 1][k];
				}
			}
		}

		printf("%d\n", DP[n][m]);
	}

	return 0;
}