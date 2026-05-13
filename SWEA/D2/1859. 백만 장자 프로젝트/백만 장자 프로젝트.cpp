#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N;
	int input;
	vector<int> v;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N;
		v.clear();
		for (int i = 0; i < N; ++i) {
			cin >> input;
			v.push_back(input);
		}

		long long profit = 0;
		long long max_price = 0;

		for (auto it = v.rbegin(); it != v.rend(); ++it) {
			if (*it > max_price) {
				max_price = *it;
				//cout << "max_price = " << max_price << "\n";
			}
			else {
				profit += max_price - *it;
				//cout << "profit = " << profit << "\n";
			}
		}

		cout << "#" << t << " " << profit << "\n";
	}


	return 0;
}