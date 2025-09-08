#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[1001];
int dp[1001];
int dp_parent[1001];

int main() {

	int answer = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int max_idx = 0;

	for (int i = 0; i < N; i++) {

		dp[i] = 1;
		dp_parent[i] = i;
		for (int j = 0; j < i; j++) {
			if (board[j] < board[i]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					dp_parent[i] = j;
				}
				//dp[i] = max(dp[i], dp[j] + 1);
				//dp_parent[i] = j;
			}
		}
		if (answer < dp[i]) {
			answer = dp[i];
			max_idx = i;
		}
	}
	cout << answer << "\n";
	vector<int> ans;
	
	int now_i = max_idx;
	while (now_i != dp_parent[now_i]) {
		ans.push_back(board[now_i]);
		now_i = dp_parent[now_i];
	}
	ans.push_back(board[now_i]);
	reverse(ans.begin(), ans.end());
	for (auto i : ans) cout << i << " ";
	cout << "\n";
	return 0;
}