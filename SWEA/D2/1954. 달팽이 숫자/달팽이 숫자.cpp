#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;
	
	for (int t = 1; t <= T; ++t) {
		cin >> N;

		vector<vector<int>> map(N, vector<int>(N, 0));
		
		int cy, cx;
		int cnt = 1;
		cy = cx = 0;
		int hbound = N;
		int lbound = 0;
		int rbound = N;
		int bbound = 0;
		int dir = 0;
		map[cy][cx] = cnt++;
		while (cnt <= N * N) {
			if (cx + dx[dir] >= rbound) {
				bbound++;
				dir = (dir + 1) % 4;
			}
			if (cy + dy[dir] >= hbound) {
				rbound--;
				dir = (dir + 1) % 4;
			}
			if (cy + dy[dir] < bbound) {
				lbound++;
				dir = (dir + 1) % 4;
			}
			if (cx + dx[dir] < lbound) {
				hbound--;
				dir = (dir + 1) % 4;
			}

			cy += dy[dir];
			cx += dx[dir];
			map[cy][cx] = cnt++;
			// printf("debug: %d %d %d %d \n", cy, cx, cnt, dir);
		}

		cout << "#" << t << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}