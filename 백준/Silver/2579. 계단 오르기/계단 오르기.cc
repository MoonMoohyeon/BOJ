#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int N;
	int input[10001];
	int DT[10001];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf(" %d", &input[i]);
	}

	DT[0] = 0;
	DT[1] = input[1];
	DT[2] = input[1] + input[2];


	for (int i = 3; i <= N; i++)
	{
		if (DT[i - 3] + input[i - 1] >= DT[i - 2])
		{
			DT[i] = DT[i - 3] + input[i - 1] + input[i];
		}
		else
		{
			DT[i] = DT[i - 2] + input[i];
		}

	}

	printf("%d", DT[N]);

	return 0;
}