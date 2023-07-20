#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long

ull DP[117];

int main(void)
{
	int n;
	scanf("%d", &n);
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;

	for (int i = 5; i <= n; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 3]);
	}

	printf("%lld\n", DP[n]);

	return 0;
}