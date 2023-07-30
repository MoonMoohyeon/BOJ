#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
using namespace std;

int N, K;
int g[1001];
int s[1001];
int b[1001];
int ranking = 0;

int main(void)
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		scanf("%d %d %d", &g[temp], &s[temp], &b[temp]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (g[i] > g[K])
		{
			ranking++;
		} 
		else if (g[i] == g[K])
		{
			if (s[i] > s[K])
			{
				ranking++;
			}
		}
		else if (s[i] == s[K])
		{
			if (b[i] > b[K])
			{
				ranking++;
			}
		}

	}

	printf("%d\n", ranking + 1);
}
