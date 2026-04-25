#include <iostream>
using namespace std;

int main(void)
{
	int N;
	unsigned long long FF[91];

	FF[0] = 0;
	FF[1] = 1;
	FF[2] = 1;
	FF[3] = 2;

	scanf("%d", &N);

	for (int i = 4; i <= N; i++)
	{
		FF[i] = FF[i - 1] + FF[i - 2];
	}

	printf("%lld", FF[N]);

	return 0;
}