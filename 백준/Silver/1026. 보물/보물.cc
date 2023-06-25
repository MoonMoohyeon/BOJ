#include <iostream>
#include <algorithm>
using namespace std;

int A[51];
int B[51];

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
	}

	sort(B, B + N);
	sort(A, A + N, greater<int>());

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		res += A[i] * B[i];
	}

	printf("%d", res);
	
	return 0;
}

