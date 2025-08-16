#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include <string>
using namespace std;

typedef long long ll;
int N, M;
int treeh[1000001];
ll ans = 0;

void bsearch(int start, int end) {
	if (start > end) return;
	ll mid = (start + end) / 2;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		if (treeh[i] - mid > 0) {
			sum += treeh[i] - mid;
		}
	}

	if (sum >= M) {
		if (ans < mid) {
			ans = mid;
		}
		bsearch(mid + 1, end);
	}
	else {
		bsearch(start, mid - 1);
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	int maxh = 0;
	for (int i = 0; i < N; i++) {
		cin >> treeh[i];
		if (treeh[i] > maxh) maxh = treeh[i];
	}

	//sort(treeh, treeh + N);
	/*
		가장 높은 나무의 높이를 끝 점으로 잡고 이진 탐색한다.
		mid 값으로 나무를 잘랐을 때의 sum을 구한다.
		sum이 M보다 큰 값 중 최소값을 구해야 한다.
		mid로 잘랐을 때 M보다 작다면 아래 범위를 탐색한다(나무를 더 잘라야 함)
		mid로 잘랐을 때 M보다 크다면 위 범위를 탐색하여 최적값을 구한다.
	*/

	bsearch(0, maxh);
	cout << ans;

	return 0;
}