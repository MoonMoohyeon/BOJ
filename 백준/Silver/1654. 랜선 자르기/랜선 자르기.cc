#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include <string>
using namespace std;

typedef long long ll;
int K, N, M;
int lancable[10001];

ll ans = 0;
void bsearch(ll start, ll end) {
	if (start > end) return;
	ll mid = (start + end) / 2;
	ll sum = 0;
	for (int i = 0; i < K; i++) {
		sum += lancable[i] / mid;
	}

	if (sum >= N) {
		ans = mid;
		bsearch(mid + 1, end);
	}
	else {
		bsearch(start, mid - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> K >> N;
	ll maxl = 0;
	for (int i = 0; i < K; i++) {
		cin >> lancable[i];
		if (lancable[i] > maxl) maxl = lancable[i];
	}

	bsearch(1, maxl);
	cout << ans;
	/*
		시작점을 0, 끝 점을 가장 긴 랜선의 길이로 잡는다.
		mid 값으로 잘랐을 때 한 랜선에서 몇 개가 나오는지 구한다.
		모든 랜선에 대해 반복하여 조각 개수를 구한다.
		잘린 조각 개수가 N보다 작으면 더 많은 조각이 필요하다 -> mid 값을 줄인다.
		잘린 조각 개수가 N보다 많으면 더 적은 조각으로 최적화한다 -> mid 값을 키운다.
	*/

	return 0;
}