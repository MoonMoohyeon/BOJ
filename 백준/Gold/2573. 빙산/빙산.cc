#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
int map[301][301];
int visited[301][301] = { 0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

// 1445273 문무현

int isinbound(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return 0;
	return 1;
}

int BFS(int srcy, int srcx) {
	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visited[i][j] = 0;
		}
	}

	visited[srcy][srcx] = 1;
	q.push({ srcy,srcx });

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		//cout << "Test\n";

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] != 0) continue;
			if (map[ny][nx] == 0) continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}

	return 0;
}

void simulation() {

	int aftermap[301][301];
	for (int i = 0; i < 301; ++i) {
		for (int j = 0; j < 301; ++j) {
			aftermap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int cnt = 0;
			if (map[i][j] != 0) {
				for (int k = 0; k < 4; ++k) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (isinbound(ny, nx)) {
						if (map[ny][nx] == 0) {
							cnt++;
						}
					}
				}
				aftermap[i][j] -= cnt;
				if (aftermap[i][j] < 0) aftermap[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < 301; ++i) {
		for (int j = 0; j < 301; ++j) {
			map[i][j] = aftermap[i][j];
		}
	}
}

void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int checksep(int cnt) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visited[i][j] == 0 && map[i][j] != 0) return cnt; // 구역이 나누어진 경우
		}
	}

	return 0;
}

int checklast() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] != 0) return 1; // 모든 땅이 0인지 확인
		}
	}
	return 0;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N;++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	while (1) {
		cnt++;
		simulation();
		int flag = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0;j < M;++j) {
				if (map[i][j] != 0) {
					BFS(i, j);
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}

		int ans = checksep(cnt);
		if (ans) {
			cout << ans << "\n";
			break;
		}
		else {
			ans = checklast();
			if (ans == 0) {
				cout << ans << "\n";
				break;
			}
		}
	}

	return 0;
}