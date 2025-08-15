#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include <string>
using namespace std;

int N, M;
vector<int> graph[1001];
int indegree[1001];
queue<int> q;
queue<int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int temp;
		cin >> temp;
		for (int j = 1; j < num; j++) {
			int a;
			cin >> a;
			graph[temp].push_back(a);
			indegree[a]++;
			temp = a;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			//cout << "push " << i << endl;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//cout << cur << endl;
		ans.push(cur);

		for (auto i = graph[cur].begin(); i != graph[cur].end(); i++) {
			if (--indegree[*i] == 0) {
				q.push(*i);
			}
		}
	}

	if (ans.size() < N) {
		cout << "0";
		return 0;
	}

	while (!ans.empty()) {
		cout << ans.front() << "\n";
		ans.pop();
	}

	return 0;
}