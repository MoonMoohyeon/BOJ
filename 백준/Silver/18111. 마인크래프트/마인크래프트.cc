#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define INF 10e8
int N, M, B;
int terra[500][500];
int maxlevel = 0, minlevel = 10e8;
int ans = INF;

int cost(int targetlevel, int b) {
	int cost = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (terra[i][j] == targetlevel) continue;

			if (terra[i][j] < targetlevel) { // 현재 땅 레벨이 목표보다 낮은 경우
				cost += targetlevel - terra[i][j];
				b -= targetlevel - terra[i][j];
			}
			else if(terra[i][j] > targetlevel) {
				cost += (terra[i][j] - targetlevel) * 2; // 깎기
				b += terra[i][j] - targetlevel;
			}

		}
	}

	if (b < 0) {
		return INF;
	}
	return cost;
}

int main(int argc, char** argv) {

	cin >> N >> M >> B;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> terra[i][j];
			if (terra[i][j] > maxlevel) maxlevel = terra[i][j];
			if (terra[i][j] < minlevel) minlevel = terra[i][j];
		}
	}

	/*
		높이 범위
		낮은 땅 <= 후보 높이 <= 높은 땅

		높이 우선 순위
		높은 땅 > 낮은 땅
		
		낮은 땅을 후보 높이로 맞출 수 있는지 확인
		-> 인벤토리의 블록 개수로 확인

		맞출 수 없는 경우
		가장 높은 땅을 한 칸씩 까서 인벤토리에 추가

		현재 목표 레벨로 낮은 땅을 채우는 비용,
		현재 목표 레벨 - 1로 높은 땅을 까는 비용
		둘 중 최소값을 일단 구해
		이걸 언제까지 구하냐?
		
		목표 레벨은 입력 중에서 가장 높은 땅에서 시작해서
		가장 낮은 땅까지 낮추면서
		모든 최소값 중 최소값을 구하면 정답
		
	*/

	int targetlevel = 0;
	for (int i = maxlevel; i >= minlevel; --i) {
		int tmp = cost(i, B);
		//cout << "tmp : " << tmp << "level : " << i << "\n";
		if (ans > tmp) {
			ans = tmp;
			targetlevel = i;
		}
	}

	cout << ans << " " << targetlevel;

	return 0;
}