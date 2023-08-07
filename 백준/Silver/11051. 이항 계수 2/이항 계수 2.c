#include <stdio.h>

int N, K;
long long DP[1001][1001];

//점화식 DP[N][K] = DP[N-1][K-1] + DP[N-1][K]
// 파스칼의 삼각형

int main()
{
	scanf("%d %d", &N, &K);

	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) DP[i][0] = 1;
			else if (j == i) DP[i][j] = 1;
			else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % 10007;
		}
			

	printf("%d\n", DP[N][K]);

    return 0;
}