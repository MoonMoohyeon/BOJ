#include <iostream>
#include <vector>
#include <algorithm>

int arr[1001] = { 0, };
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, idx, h;
	cin >> N;
	
	int max_h = 0;
	int max_idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> idx >> h;

		if (max_h < h) {
			max_idx = idx;
			max_h = h;
		}

		arr[idx] = h;
	}

	int ans = 0;
	int r_v = 0;
	for (int id = 0; id <= max_idx; id++) {
	
		r_v = max(r_v, arr[id]);
		ans += r_v;
	}

	r_v = 0;
	for (int id = 1000; id > max_idx; id--) {

		r_v = max(r_v, arr[id]);
		ans += r_v;
	}
	cout << ans << "\n";
	return 0;
}