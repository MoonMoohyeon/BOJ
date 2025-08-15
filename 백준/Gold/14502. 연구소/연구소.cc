#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int N, M;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int boundCheck(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M) return 0;
	return 1;
}

queue<pair<int, int>> q;
vector<pair<int, int>> v;
vector<pair<int, int>> v2;
int arr[9][9];
int arrcpy[9][9];

void BFS(int i, int j) {
	pair<int, int> cur;
	q.push({ i,j });
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			if (!boundCheck(cur.first + dx[k], cur.second + dy[k])) continue;
			if (arrcpy[cur.first + dx[k]][cur.second + dy[k]] == 0) {
				q.push({ cur.first + dx[k], cur.second + dy[k] });
				arrcpy[cur.first + dx[k]][cur.second + dy[k]] = 2;
			}
		}
	}
}

void buildWall(int i, int j) {
	arrcpy[i][j] = 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	/*
		최대 8*8 영역에서 벽을 3개 세우는 모든 경우의 수에 대하여 BFS를 시행한다.
		시행 후 안전 영역의 크기를 구하고, 영역의 크기가 최대인 경우를 출력한다.
	*/


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			arr[i][j] = arr[i][j];
			if (arr[i][j] == 0) v.push_back({ i,j }); // 0인 원소, 벽 세우기 후보지
			if (arr[i][j] == 2) v2.push_back({ i,j }); // 2인 원소, BFS 시작점
		}
	}

	int cnt, max;
	cnt = max = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {

				for (int l = 0; l < N; l++) {
					for (int m = 0; m < M; m++) {
						arrcpy[l][m] = arr[l][m];
					}
				}

				buildWall(v[i].first, v[i].second); // 벽 세우기 모든 경우의 수
				buildWall(v[j].first, v[j].second);
				buildWall(v[k].first, v[k].second);

				for (int l = 0; l < v2.size(); l++) {
					BFS(v2[l].first, v2[l].second);
				}

				cnt = 0;
				for (int l = 0; l < N; l++) {
					for (int m = 0; m < M; m++) {
						if (arrcpy[l][m] == 0) cnt++;
					}
				}

				if (cnt > max) max = cnt;
			}
		}
	}

	cout << max << endl;

	return 0;
}