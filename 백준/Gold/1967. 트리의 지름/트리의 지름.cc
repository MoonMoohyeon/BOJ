#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{

	int now_node;
	int cost;
};

int visited[10001];
vector<Edge> adj[10001];
int N;

int max_len = 0;
int max_idx = 0;

void init() {

	cin >> N;

	int start, end, weight;
	for (int i = 0; i < N - 1; i++) {

		cin >> start >> end >> weight;
		adj[start].push_back({ end, weight });
		adj[end].push_back({ start, weight });
	}
}

void dfs(int node, int sum_dist) {

	visited[node] = 1;

	if (sum_dist > max_len) {

		max_len = sum_dist;
		max_idx = node;
	}


	for (int i = 0; i < adj[node].size(); i++) {
		
		Edge next = adj[node][i];
		if (visited[next.now_node]) continue;
		dfs(next.now_node, sum_dist + next.cost);
	}
}

void visited_init() {

	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

void process() {

	dfs(1, 0);

	visited_init();
	max_len = 0;

	dfs(max_idx, 0);
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	process();

	cout << max_len << "\n";

	return 0;
}