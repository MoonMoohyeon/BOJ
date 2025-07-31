#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int N = 19;
int board[19][19];

// 방향: → ↘ ↓ ↙ (중복 탐색 방지용 4방향)
int dx[4] = { 1,1,0,-1 };
int dy[4] = { 0,1,1,1 };
vector<pair<int, int>> whiteCord;
vector<pair<int, int>> blackCord;

bool isValid(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void solution() {
	for (auto bCord : blackCord) {
		int x = bCord.first, y = bCord.second;

		for (int dir = 0; dir < 4; dir++) {
			int count = 1;
			// 양방향 탐색
			// 방향 결정 변수
			int k = 1;
			deque<pair<int, int>> Candidate;
			Candidate.push_back({ x,y });
			for (int len = 1; ; len++) {

				//정방향 탐색
				int nx = x + (dx[dir] * len) * k;
				int ny = y + (dy[dir] * len) * k;

				if (!isValid(nx, ny) || board[ny][nx] != 1) break;
				Candidate.push_back({ nx,ny });
				count++;
			}
			k = -1;
			for (int len = 1; ; len++) {

				//정방향 탐색
				int nx = x + (dx[dir] * len) * k;
				int ny = y + (dy[dir] * len) * k;

				if (!isValid(nx, ny) || board[ny][nx] != 1) break;
				Candidate.push_back({ nx,ny });
				count++;
			}
			/*cout << "black" << endl;
			cout << "x : " << x << " y : " << y << endl;
			cout << count << '\n';*/
			if (count == 5) {
				/*for (int i = 0; i < Candidate.size(); i++) {
					cout << "x: " << Candidate[i].first << " y: " << Candidate[i].second << '\n';
				}*/
				sort(Candidate.begin(), Candidate.end());
				cout << 1 << '\n';
				cout << Candidate.front().second + 1 << " " << Candidate.front().first + 1;
				return;
			}
		}
	}

	for (auto wCord : whiteCord) {
		int x = wCord.first, y = wCord.second;

		for (int dir = 0; dir < 4; dir++) {
			int count = 1;
			// 양방향 탐색
			// 방향 결정 변수
			int k = 1;
			deque<pair<int, int>> Candidate;
			Candidate.push_back({ x,y });
			for (int len = 1; ; len++) {

				//정방향 탐색
				int nx = x + (dx[dir] * len) * k;
				int ny = y + (dy[dir] * len) * k;

				if (!isValid(nx, ny) || board[ny][nx] != 2) break;
				Candidate.push_back({ nx,ny });
				count++;
			}
			k = -1;
			for (int len = 1; ; len++) {

				//정방향 탐색
				int nx = x + (dx[dir] * len) * k;
				int ny = y + (dy[dir] * len) * k;

				if (!isValid(nx, ny) || board[ny][nx] != 2) break;
				Candidate.push_back({ nx,ny });
				count++;
			}
			/*cout << "white, dir : " << dir << endl;
			cout << "x : " << x << " y : " << y << endl;
			cout << count << '\n';*/


			if (count == 5) {

				sort(Candidate.begin(), Candidate.end());
				/*for (int i = 0; i < Candidate.size(); i++) {
					cout << Candidate[i].first << " " << Candidate[i].second << '\n';
				}*/
				cout << 2 << '\n';
				cout << Candidate.front().second + 1 << " " << Candidate.front().first + 1;
				return;
			}
		}
	}

	cout << 0 << '\n';
	return;
}

int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) blackCord.push_back({ j, i });
			else if (board[i][j] == 2) whiteCord.push_back({ j, i });
		}
	}
	solution();
}