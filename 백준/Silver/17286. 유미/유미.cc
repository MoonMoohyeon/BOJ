#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
#define INF 10e8

int N = 3;
pair<int,int> character[3];

double caldist(int srcy, int srcx, int dsty, int dstx) {
	return sqrt(pow(abs(srcy - dsty),2) + pow(abs(srcx - dstx),2));
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> order = { 1, 2, 3 };

	int starty, startx;
	cin >> starty >> startx;
	for (int i = 1; i <= N; ++i) {
		int y, x;
		cin >> y >> x;
		character[i] = { y,x };
	}
	
	/*
		1 2 3
		1 3 2
		2 1 3
		2 3 1
		3 1 2
		3 2 1
	*/
	double ans = INF;
	int yumiy, yumix;
	do {
		double sum = 0;
		yumiy = starty;
		yumix = startx;
		for (int i : order) {
			sum += caldist(yumiy, yumix, character[i].first, character[i].second);
			yumiy = character[i].first;
			yumix = character[i].second;
		}
		ans = min(ans, sum);
	} while (next_permutation(order.begin(), order.end()));

	cout << floor(ans);

	return 0;
}