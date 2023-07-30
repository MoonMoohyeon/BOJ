#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
using namespace std;

int N;
vector<int> v;
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", v[i]);
	}
	

}
