#include <stdio.h>
#include <stdlib.h>

int parent[1000001];

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) parent[y] = x;
	
}

int isUnion(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return 1;
	return 0;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < 1000001; i++)
		parent[i] = i;


	int o, a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &o, &a, &b);
		if (o == 0)
		{
			Union(a, b);
		}
		else
		{
			if (isUnion(a, b) == 1) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}