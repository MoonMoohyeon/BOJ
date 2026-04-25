#include <iostream>
using namespace std;

int mark[101] = { 0, };
int graph[101][101] = {
		{0, }
};

void DFS(int start)
{
	if (mark[start] == 1) return;
	mark[start] = 1;
	for (int i = 0; i < 101; i++)
	{
		if (graph[start][i] == 1) DFS(i);
	}
}

int main(void)
{
	int n, edge;
	scanf("%d", &n);
	scanf("%d", &edge);
	int from;
	int to;
	for (int i = 0; i < edge; i++)
	{
		scanf("%d %d", &from, &to);
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	DFS(1);

	int count = 0;
	for (int i = 0; i < 101; i++)
	{
		if (mark[i] == 1) count++;
	}

	printf("%d", --count);

	return 0;
}