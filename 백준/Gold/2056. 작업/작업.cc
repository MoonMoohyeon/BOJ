#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N;
int tim[10001];
int indegree[10001];
int DP[10001];
vector<int> graph[10001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t, num;
		cin >> t >> num;
		tim[i] = t;
		for (int j = 0; j < num; j++) {
			int input;
			cin >> input;
			graph[input].push_back(i);
			indegree[i]++;

		}
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			DP[i] = tim[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i = graph[cur].begin(); i != graph[cur].end(); i++) {
			DP[*i] = max(DP[*i], DP[cur] + tim[*i]);
			if (--indegree[*i] == 0) {
				q.push(*i);
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (DP[i] > ans) ans = DP[i];
	}
	cout << ans;

	return 0;
}