#include <iostream>
#include <algorithm>

using namespace std;

int board[1001];
int dp[1001];

int main() {

	int answer = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}


	for (int i = 0; i < N; i++) {

		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (board[j] > board[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(dp[i], answer);
	}
	cout << answer << "\n";
	return 0;
}