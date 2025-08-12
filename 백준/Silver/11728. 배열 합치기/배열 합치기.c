#include <stdio.h>
#include <string.h>

int A[1000001];
int B[1000001];
int sum[2000003];

int main(void)
{
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &B[i]);
	}

	int ap = 0;
	int bp = 0;
	for (int i = 0; i < N + M; i++)
	{
		if (ap >= N)
		{
			sum[i] = B[bp++];
		}
		else if (bp >= M)
		{
			sum[i] = A[ap++];
		}
		else if (A[ap] >= B[bp])
		{
			sum[i] = B[bp++];
		}
		else
		{
			sum[i] = A[ap++];
		}
	}

	for (int i = 0; i < N + M; i++)
	{
		printf("%d ", sum[i]);
	}
	
	return 0;
}

