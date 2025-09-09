#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, M;

vector<int> in_degree;
vector<int> result;
vector<int> time_vec;
vector<vector<int>> adj;
int answer = 0;

int target_num = 0;

void init() {

	cin >> N >> M;

	in_degree.assign(N + 1, 0);
	result.assign(N + 1, 0);
	time_vec.assign(N + 1, 0);
	adj.assign(N + 1, {});
	answer = 0;

	for (int i = 1; i <= N; i++) {
		
		cin >> time_vec[i];
	}

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		adj[start].push_back(end);
		in_degree[end]++;
	}
	cin >> target_num;
}

void Topology_Sort() {

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) q.push(i);
		result[i] = time_vec[i];
	}

	for (int i = 1; i <= N; i++) {
		answer = max(answer, time_vec[i]);
	}

	while (!q.empty()) {

		int now_node = q.front();
		q.pop();

		for (int i = 0; i < adj[now_node].size(); i++) {

			int next_node = adj[now_node][i];

			in_degree[next_node]--;
			if (in_degree[next_node] == 0) {
				q.push(next_node);
			}
			result[next_node] = max(result[next_node], result[now_node] + time_vec[next_node]);
			answer = max(answer, result[next_node]);
		}
	}
}
		

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case < T + 1; test_case++) {

		init();

		Topology_Sort();

		cout << result[target_num] << "\n";
	}

	return 0;
	
}