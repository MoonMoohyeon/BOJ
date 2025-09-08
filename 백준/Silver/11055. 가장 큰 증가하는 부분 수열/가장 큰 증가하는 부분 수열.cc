#include <iostream>
#include <algorithm>

using namespace std;

int board[1001];
int dp[1001];
int dp_sum[1001];

int main() {

	int answer = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}


	for (int i = 0; i < N; i++) {

		dp[i] = 1;
		dp_sum[i] = board[i];
		for (int j = 0; j < i; j++) {
			if (board[j] < board[i]) {
				dp_sum[i] = max(dp_sum[i], dp_sum[j] + board[i]);
			}
		}
		answer = max(dp_sum[i], answer);
	}
	cout << answer << "\n";
	return 0;
}