#include <iostream>
#include <algorithm>
using namespace std;

int A[101][101];
int B[101][101];
int sum[101][101];

int main(void)
{
	int N, M, K;
	int tmp;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &tmp);
			A[i][j] = tmp;
		}
	}

	scanf("%d %d", &M, &K);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			scanf("%d", &tmp);
			B[i][j] = tmp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
			{
				sum[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

