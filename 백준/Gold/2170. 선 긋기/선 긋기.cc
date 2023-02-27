#include <iostream>
#include <algorithm>
using namespace std;

int X[1000001] = { 0, };
int Y[1000001] = { 0, };

int main(void)
{
	int N;
	scanf("%d", &N);
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &X[i], &Y[i]);
		if (X[i] > max) max = X[i];
		if (Y[i] > max) max = Y[i];
	}

	sort(X, X + N);
	sort(Y, Y + N);

	int sum = max - X[0];
	for (int i = 0; i < N; i++)
	{
		if (Y[i] < X[i + 1])
		{
			sum -= X[i + 1] - Y[i];
		}
	}

	printf("%d", sum);

	return 0;
}

