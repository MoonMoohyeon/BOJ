#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int N;
int map[101][101];
int visited[101][101];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int isinbound(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) return 0;
	return 1;
}

void BFS(int srcy, int srcx, int k) {
	queue<pair<int, int>> q;

	visited[srcy][srcx] = 1;
	q.push({ srcy,srcx });

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (!isinbound(ny, nx)) continue;
			if (visited[ny][nx] != 0) continue;
			if (map[ny][nx] <= k) continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int max_height = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] > max_height) {
				max_height = map[i][j];
			}
		}
	}

	int ans = 0;

	for (int k = 0; k <= max_height; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				visited[i][j] = 0;
			}
		}

		int cnt = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j] > k && visited[i][j] == 0) {
					cnt++;
					BFS(i, j, k);
				}
			}
		}

		if (cnt > ans) {
			ans = cnt;
		}
	}

	cout << ans << "\n";

	return 0;
}
