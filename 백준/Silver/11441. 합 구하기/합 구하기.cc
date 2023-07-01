#include <iostream>
using namespace std;

int arr[100001];
int prefix[100001];

int main(void)
{
	int N, M;
	int start, end;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	prefix[0] = arr[0];
	for (int i = 1; i <= N; i++)
	{
		prefix[i] = prefix[i - 1] + arr[i];
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", prefix[end - 1] - prefix[start - 2]);
	}

	return 0;
}
