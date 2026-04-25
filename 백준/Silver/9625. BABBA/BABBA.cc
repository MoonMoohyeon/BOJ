#include <iostream>
using namespace std;

int main(void)
{
	int K;
	scanf("%d", &K);

	int A[46];
	int B[46];

	A[1] = 0;
	A[2] = 1;
	A[3] = 1;
	B[1] = 1;
	B[2] = 1;
	B[3] = 2;

	for (int i = 4; i <= K; i++)
	{
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	printf("%d %d", A[K], B[K]);

	
	return 0;
}

