#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N;
int arr[101] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int input;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int i = 0; i < 101; ++i) {
			arr[i] = 0;
		}
	
		for (int i = 0; i < 1000; ++i) {
			cin >> input;
			arr[input]++;
		}

		int max_score = -1;
		int res = -1;
		for (int i = 0; i < 101; ++i) {
			if (arr[i] >= max_score) {
				max_score = arr[i];
				res = i;
			}
		}

		cout << "#" << t << " " << res << "\n";
	}


	return 0;
}