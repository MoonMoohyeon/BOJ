#include <bits/stdc++.h>
using namespace std;

int N;
struct Frame {
	int n, from, via, to;
	int stage; // 0: 처음, 1: 왼쪽 끝 탐색 끝나고 돌아옴, 2: 출력 후 오른쪽 호출 준비
};
/*
	2번에 N-1개의 탑이 순서대로 있어야한다.
*/
void hanoi(int N, int from, int via, int to) {
	if (N == 1) {
		cout << from << " " << to << '\n';
		return;
	}
	// N-1개를 보조 기둥으로
	hanoi(N - 1, from, to, via);
	cout << from << " " << to << '\n';
	// 보조기둥에 있던거를 마지막으로
	hanoi(N - 1, via, from, to);
}
int main() {
	cin >> N;
	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, 1, 2, 3);
}