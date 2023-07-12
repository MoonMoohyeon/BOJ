#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
int mark[100001] = { 0, };
int res[100001] = { 0, };
queue<int> q;
int cnt = 0;

void dfs(int r) {
	if (mark[r] == 1) return;
	mark[r] = 1;
	res[r] = ++cnt;
	for (int i = 0; i < graph[r].size(); i++)
	{
		dfs(graph[r][i]);
	}
}
int main() {
	int n, m, r;
	int a, b;
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", res[i]);
	}

}