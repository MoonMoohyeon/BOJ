#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull N, M;
int graph[101][101] = { 0, };
const int INF = 10e8;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	ull start = 0;
	ull end = N;
	ull ans = 0;
	while (start <= end) {
		ull mid = (start + end) / 2;
		if (pow(mid, 2) == N) {
			ans = mid;
			break;
		}
		else if (pow(mid, 2) < N) {
			start = mid + 1;
		}
		else {
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans;

	return 0;
}