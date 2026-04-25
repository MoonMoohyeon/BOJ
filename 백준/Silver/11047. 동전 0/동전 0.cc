#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> coin;
	int value;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &value);
		coin.push_back(value);
	}
	sort(coin.begin(), coin.end());

	int count = 0;
	while (N != 0)
	{
		while(K >= coin[N-1])
		{
			K -= coin[N-1];
			count++;
		}
		N--;
	}

	printf("%d", count);

	return 0;
}