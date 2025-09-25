#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int T, N;
multimap<pair<double,int>, string> m;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (1) {
		cin >> T;
		if (T == 0) break;

		m.clear();

		string name;
		double height;
		for (int i = 0; i < T; ++i) {
			cin >> name >> height;
			m.insert({ { height, -i }, name });
		}

		double maxheight = m.rbegin()->first.first;
		for (auto i = m.rbegin(); i != m.rend(); ++i) {
			double curheight = i->first.first;
			if (curheight == maxheight) {
				cout << i->second << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}