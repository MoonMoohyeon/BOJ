#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
long mark[100001] = { 0, };
long res[100001] = { 0, };
queue<int> q;
int cnt = 0;

void bfs(int r) {
	q.push(r);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (mark[next] == -1) {
				res[next] = ++cnt;
				mark[next] = mark[cur] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m, r;
	int a, b;
	memset(mark, -1, sizeof(mark));
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	mark[r] = 0;
	res[r] = ++cnt;
	bfs(r);

	long long val = 0;
	for (int i = 1; i <= n; i++) {
		val = val + mark[i] * res[i];
	}

	printf("%lld\n", val);

	return 0;
}
