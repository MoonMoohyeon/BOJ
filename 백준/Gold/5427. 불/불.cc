#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

int M, N;
vector<string> MAP;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<vector<bool>> visited;
pair<int, int> human;
vector<pair<int, int>> fire;
bool isValid(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
bool escape(int x, int y) {
	return x == 0 || x == M - 1 || y == 0 || y == N - 1;
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << MAP[i][j] << "";
		}
		cout << '\n';
	}
	cout << '\n';
}
void bfs() {
	deque<tuple<int, int,int>> human_q;
	deque<pair<int, int>> fire_q;
	if (escape(human.first, human.second)) {
		cout << "1\n";
		return;
	}

	human_q.push_back(make_tuple(human.first,human.second ,1));
	for (int i = 0; i < fire.size(); i++) {
		fire_q.push_back(fire[i]);
	}

	while (!human_q.empty()) {
		// 사람 먼저 이동
		// 불태우기
		int fire_size = fire_q.size();
		while (fire_size--) {
			pair<int, int> fireCord = fire_q.front();
			fire_q.pop_front();

			int fx = fireCord.first, fy = fireCord.second;
			for (int i = 0; i < 4; i++) {
				int nx, ny;
				nx = fx + dx[i]; ny = fy + dy[i];

				if (!isValid(nx, ny)) continue;
				if (MAP[ny][nx] == '.' || MAP[ny][nx] == '@') {
					MAP[ny][nx] = '*';
					fire_q.push_back({ nx, ny });
				}
			}
		}

		int human_size = human_q.size();
		while (human_size--) {
			tuple<int, int, int> cord = human_q.front();
			human_q.pop_front();
			int x, y, count;
			x = get<0>(cord);
			y = get<1>(cord);
			count = get<2>(cord);

			visited[y][x] = true;
			for (int i = 0; i < 4; i++) {
				int nx, ny;
				nx = x + dx[i]; ny = y + dy[i];

				if (!isValid(nx, ny))continue;
				if (visited[ny][nx]) continue;
				if (MAP[ny][nx] != '.') continue;

				MAP[ny][nx] = '@';
				if (escape(nx, ny)) {
					cout << count + 1 << '\n';
					return;
				}
				visited[ny][nx] = true;
				human_q.push_back({ nx,ny,count + 1 });

			}
		}
	}
	
	cout << "IMPOSSIBLE\n";
	return;
}
void init() {
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == '*') {
				fire.push_back({ j,i });
			}
			if (MAP[i][j] == '@') {
				human = { j,i };
			}
		}
	}
}
int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N;
		MAP.assign(N, "");
		visited.assign(N, vector<bool>(M, false));
		fire.resize(0);

		init();
		bfs();
	}
}