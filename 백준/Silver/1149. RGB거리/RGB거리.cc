#include <iostream>
#include <algorithm>
using namespace std;

int DP[1001][3];
int RED[1001], GREEN[1001], BLUE[1001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &RED[i], &GREEN[i], &BLUE[i]);
	}

		DP[1][0] = RED[1];
		DP[1][1] = GREEN[1];
		DP[1][2] = BLUE[1];

	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + RED[i];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + GREEN[i];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + BLUE[i];
	}

	int mini = min({ DP[N][0], DP[N][1], DP[N][2] });
	printf("%d", mini);

	return 0;
}