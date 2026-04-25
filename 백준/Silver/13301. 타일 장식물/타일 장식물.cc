#include <iostream>
#include <algorithm>
#include <vector>

long long DP[81];

int main(void)
{
	int N;
	scanf("%d", &N);

	DP[1] = 4;
	DP[2] = 6;
	DP[3] = 10;
	DP[4] = 16;

	for (int i = 5; i <= N; i++)
	{
		DP[i] = DP[i - 2] + DP[i - 1];
	}

	printf("%lld", DP[N]);

	return 0;
}

