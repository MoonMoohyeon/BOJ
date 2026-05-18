#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K, max_length;

int boundary_check(int x, int y, int n) {
	if (x <= 0 || y <= 0 || x > n || y > n) return 0;
	else return 1;
}

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int mountain[9][9];
int visited[9][9];

void DFS(int r, int c, bool used, int length) {
	max_length = max(max_length, length);

	for (int d = 0; d < 4; ++d) {
		int nr = r + dx[d];
		int nc = c + dy[d];

		if (!boundary_check(nr, nc, N)) continue;
		if (visited[nr][nc]) continue;

		// 그냥 내려갈 수 있는 경우
		if (mountain[nr][nc] < mountain[r][c]) {
			visited[nr][nc] = 1;
			DFS(nr, nc, used, length + 1);
			visited[nr][nc] = 0;
		}

		// 깎으면 내려갈 수 있는 경우
		else if (!used && mountain[nr][nc] - K < mountain[r][c]) {
			int original = mountain[nr][nc];

			mountain[nr][nc] = mountain[r][c] - 1;

			visited[nr][nc] = 1;
			DFS(nr, nc, true, length + 1);
			visited[nr][nc] = 0;

			mountain[nr][nc] = original;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int input;
	cin >> T;

	for (int t = 1; t <= T; ++t) {

		for (int i = 1; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				mountain[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		cin >> N >> K;

		int max_height = 0;
		max_length = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> input;
				mountain[i][j] = input;
				if (input > max_height) max_height = input;
			}
		}


		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (mountain[i][j] == max_height) {
					/* DFS 시작 */
					visited[i][j] = 1;
					DFS(i, j, 0, 1);
					visited[i][j] = 0;
				}
			}
		}

		cout << "#" << t << " " << max_length << "\n";

	}


	return 0;
}