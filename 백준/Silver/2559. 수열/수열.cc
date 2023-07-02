#include <iostream>
#include <limits.h>
using namespace std;

int arr[100001];
int prefix[100001];

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	prefix[0] = arr[0];
	for (int i = 1; i <= N; i++)
	{
		prefix[i] = prefix[i - 1] + arr[i];
	}

	/*for (int i = 0; i < N; i++)
	{
		printf("%d = %d\n", i, prefix[i]);
	}*/

	int max = INT_MIN;
	for (int i = -1; i < N - K; i++)
	{
		if (prefix[i + K] - prefix[i] > max) {
			max = prefix[i + K] - prefix[i];
		}
		//printf("num = %d\n", prefix[i + K] - prefix[i]);
	}

	printf("%d\n", max);

	return 0;
}
