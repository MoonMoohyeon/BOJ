#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, K;
int wheel[4][8];

void rotation(int num, int dir) {
	if (dir == 1) { // 시계 방향 회전
		int tmp = wheel[num][7];
		for (int i = 7; i >= 1; --i) {
			wheel[num][i] = wheel[num][i - 1];
		}
		wheel[num][0] = tmp;
	}
	else { // 반시계 방향 회전
		int tmp = wheel[num][0];
		for (int i = 0; i < 7; ++i) {
			wheel[num][i] = wheel[num][i + 1];
		}
		wheel[num][7] = tmp;
	}
}

void simulation(int num, int dir, int prev) {
	// 왼쪽 자석 확인
	if (num > 0 && prev != num - 1) {
		if (wheel[num][6] != wheel[num - 1][2]) {
			simulation(num - 1, -dir, num);
		}
	}

	// 오른쪽 자석 확인
	if (num < 3 && prev != num + 1) {
		if (wheel[num][2] != wheel[num + 1][6]) {
			simulation(num + 1, -dir, num);
		}
	}
    
    // 현재 자석 회전
	rotation(num, dir);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int input;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> K;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 8; ++j) {
				cin >> input;
				wheel[i][j] = input;
			}
		}
		
		for (int i = 0; i < K; ++i) {
			int num;
			int dir;
			cin >> num >> dir;
			--num;
			simulation(num, dir, -1);
		}

		int ans = 0;

		for (int i = 0; i < 4; ++i) {
			if (wheel[i][0] == 1) {
				ans += (1 << i);
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}