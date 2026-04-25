#include <iostream>
#include <algorithm>
using namespace std;

int rope[100001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &rope[i]);
	}

	sort(rope, rope + N, greater<int>());
	int res = rope[0];
	for (int i = 0; i < N; i++)
	{
		if (rope[i] * (i + 1) > res)
		{
			res = rope[i] * (i + 1);
		}
	}

	printf("%d", res);

	return 0;
}

