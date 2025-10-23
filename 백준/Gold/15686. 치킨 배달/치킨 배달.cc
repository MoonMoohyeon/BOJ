#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int N, M;
int map[51][51];
vector<pair<int, int>> cand;
vector<pair<int, int>> house;
int selected[14];

int getDist(int srcy, int srcx, int dsty, int dstx) {
	return abs(srcy - dsty) + abs(srcx - dstx);
}

int ans = 10e8;

void selection(int cnt, int start) {
	if (cnt == M) {
		int temp = 0;

		for (int i = 0; i < house.size(); ++i) {
			int min_dist = 10e8;

			for (int k = 0; k < cand.size(); ++k) {
				if (selected[k] == 1) {
					int dist = getDist(house[i].first, house[i].second, cand[k].first, cand[k].second);
					min_dist = min(min_dist, dist);
				}
			}
			temp += min_dist;
		}

		ans = min(ans, temp);
		return;
	}

	for (int i = start; i < cand.size(); ++i) {
		selected[i] = 1;
		selection(cnt + 1, i + 1);
		selected[i] = 0;
	}
}


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			else if (map[i][j] == 2) cand.push_back({ i,j });
		}
	}

	selection(0, 0);
	cout << ans;

	return 0;
}