#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
#define INF 10e8

int N;
struct point {
	int x, y;

	/*bool operator<(point& next) const {
		return y < next.y;
		return x < next.x;
		return false;
	}*/

	bool operator < (point& next) {
		if (y == next.y) {
			return x < next.x;
		}
		return y < next.y;
	}
};
vector<point> arr(100000);

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int ty, tx;
		cin >> tx >> ty;
		arr[i].x = tx;
		arr[i].y = ty;
		
	}

	sort(arr.begin(), arr.begin() + N);
	for (int i = 0; i < N; ++i) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}

	return 0;
}