#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N, M;
char map[13][7];
int visited[13][7];
int explode[13][7] = { 0, };
int blockcnt = 0;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int isinbound(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return 0;
	return 1;
}

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			explode[i][j] = 0;
		}
	}
}

void printmap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void printvisit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << explode[i][j];
		}
		cout << endl;
	}
}

void packblock() {
	/*
		열별로 확인해서 맨 아래 칸부터 위쪽 칸까지 빈 공간이 있는 경우 내린다.
	*/
	for (int t = 0; t < N; t++) {
		for (int j = 0; j < M; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (map[i][j] != '.' && i != N - 1 && isinbound(i+1, j) && map[i+1][j] == '.') {
					map[i + 1][j] = map[i][j];
					map[i][j] = '.';
				}
			}
		}
	}
}

void BFS(int y, int x, char color) {
	q.push({ y,x });
	visited[y][x] = 1;
	blockcnt++;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isinbound(ny, nx) && visited[ny][nx] == 0 && map[ny][nx] == color) {
				visited[ny][nx] = 1;
				blockcnt++;
				q.push({ ny,nx });
			}
		}
	}
}

void puyo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (explode[i][j] == 1) {
				map[i][j] = '.';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	N = 12;
	M = 6;
	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}

	/*
		모든 칸에 대하여 BFS/DFS를 수행한다.
		같은 색 블록 카운트가 4 이상이면 없앤다.
		없어진 블록 위에 있는 블록들을 아래로 내린다.
	*/
	
	int puyocnt = 0;
	while (1) {
		int flag = 0;

		reset();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != '.') {
					blockcnt = 0;
					if (map[i][j] != '.' && visited[i][j] == 0) {
						BFS(i, j, map[i][j]);
						//cout << "bcnt : " << blockcnt << endl;
					}
					if (blockcnt < 4) {
						for (int i = 0; i < N; i++) {
							for (int j = 0; j < M; j++) {
								visited[i][j] = 0;
							}
						}
					}
					if (blockcnt >= 4) {
						//cout << "puyo " << i << " " << j << " " << map[i][j] << endl;
						//puyo();
						for (int r = 0; r < N; r++) {
							for (int c = 0; c < M; c++) {
								if (visited[r][c] == 1) {
									explode[r][c] = 1;
								}
							}
						}
						flag = 1;
					}
				}
			}
		}

		if (!flag) break;
		//printmap();
		//printvisit();
		puyocnt++;
		puyo();
		packblock();
	}

	cout << puyocnt;


	return 0;
}