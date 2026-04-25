#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main(void)
{
	int P, N;
	scanf("%d %d", &P, &N);
	int tmp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());
	
	int i = 0;
	int count = 0;
	while (P < 200)
	{
		P += vec[i++];
		count++;
		if (i >= N) break;
	}

	printf("%d", count);

	return 0;
}