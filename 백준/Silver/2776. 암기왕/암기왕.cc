#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, m, tmp;
		cin >> n;
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			s.insert(tmp);
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			if (s.find(tmp) == s.end()) cout << "0\n";
			else cout << "1\n";
		}
	}
}