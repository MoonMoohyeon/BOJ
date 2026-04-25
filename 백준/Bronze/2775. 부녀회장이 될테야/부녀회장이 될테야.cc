#include <iostream>
using namespace std;

int DP[15][15];

int main(void)
{
	int T, n, k;

	for (int i = 1; i < 15; i++)
	{
		DP[0][i] = i;
	}

	for (int k = 1; k < 15; k++)
	{
		for (int i = 1; i < 15; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				DP[k][i] += DP[k - 1][j];
			}
		}
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		scanf("%d", &k);
		printf("%d\n", DP[n][k]);
	}

	return 0;
}