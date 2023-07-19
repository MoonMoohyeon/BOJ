#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long

int DP[1000001];

int main(void)
{
	int n;
	scanf("%d", &n);
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
	}

	printf("%d\n", DP[n] % 15746);

	return 0;
}

/*
1
1 00
100 111 001
1111 1100 1001 0011 0000
11111 11100 11001 10011 00111 00001 00100 10000
*/