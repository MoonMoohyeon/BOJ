#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int input;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int res = 0;

		for (int i = 0; i < 10; ++i) {
			cin >> input;
			if (input % 2 == 1) res += input;
		}

		cout << "#" << t << " " << res << "\n";
	}


	return 0;
}