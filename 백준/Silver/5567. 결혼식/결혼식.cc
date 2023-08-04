#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

vector<int> graph[501];
int mark[501] = { 0, };
int cnt = 0;
queue<int> q;

void bfs(int r) {
	q.push(r);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (mark[next] == -1) {
				mark[next] = mark[cur] + 1;
				if (mark[next] >= 0 && mark[next] <= 1 && next != 1) cnt++;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m;
	int a, b;
	memset(mark, -1, sizeof(mark));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);
	//for (int i = 1; i <= n; i++) {
	//	printf("%d\n", mark[i]);
	//}

	printf("%d\n", cnt);

	return 0;
}