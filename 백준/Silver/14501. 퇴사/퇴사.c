#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
int T[16];
int P[16];
int DP[16];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &T[i + 1], & P[i + 1]);
	}

	int tmp = 0;
	for (int i = 1; i <= N + 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (DP[j] > tmp) tmp = DP[j];
		}
		DP[i] = tmp;
		DP[i + T[i]] = max(DP[i] + P[i], DP[i + T[i]]);
	}

	int max = 0;
	for (int i = 1; i <= N + 1; i++)
	{
		if (DP[i] > max) max = DP[i];
		//printf("%d ", DP[i]);
	}
	
	printf("%d", max);
	

	return 0;
}
