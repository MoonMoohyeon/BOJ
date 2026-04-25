#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;

int main(void)
{
	int A, K;
	int temp;
	scanf("%d %d", &A, &K);
	for (int i = 0; i < A; i++)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());
	printf("%d", vec[K-1]);

	return 0;
}

