#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int N, M;
int teamtable[21][21];
int visited[21] = { 0, };
vector<vector<int>> start;
vector<vector<int>> link;
int selected[21];
int tc = 0;

int maketeam(int cnt, int next) {
	if (cnt >= N/2) {
		vector<int> tstart;
		vector<int> tlink;
		for (int i = 1; i <= N; i++) {
			if (selected[i]) {
				tstart.push_back(selected[i]);
			}
			else {
				tlink.push_back(i);
			}
		}
		start.push_back(tstart);
		link.push_back(tlink);
		return 1;
	}

	for (int i = next; i <= N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			selected[i] = i;
			maketeam(cnt + 1, i + 1);
			visited[i] = 0;
			selected[i] = 0;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> teamtable[i][j];
		}
	}

	/*
		N/2 vs N/2로 중복 없이 팀을 분배하는 경우의 수를 모두 찾는다.
		팀 전력을 구한 후 최소가 되는 값을 찾는다.

		N/2로 선택하는 경우의 수 == 중복 없이 N/2개를 선택하는 경우의 수
	*/

	maketeam(0, 1);

	//for (int i = 0; i < start.size(); i++) {
	//	cout << "start team " << i << " : ";
	//	for (auto j = start[i].begin(); j != start[i].end(); j++) {
	//		cout << *j << " ";
	//	}
	//	cout << endl;
	//}

	//for (int i = 0; i < link.size(); i++) {
	//	cout << "link team " << i << " : ";
	//	for (auto j = link[i].begin(); j != link[i].end(); j++) {
	//		cout << *j << " ";
	//	}
	//	cout << endl;
	//}

	int startscore, linkscore;
	int ans = 10e8;
	for (int i = 0; i < start.size(); i++) { // startsize == linksize
		startscore = linkscore = 0;
		for (auto j = start[i].begin(); j != start[i].end(); j++) {
			for (auto k = j + 1; k != start[i].end(); k++) {
				startscore += teamtable[*j][*k];
				startscore += teamtable[*k][*j];
			}
		}

		for (auto j = link[i].begin(); j != link[i].end(); j++) {
			for (auto k = j + 1; k != link[i].end(); k++) {
				linkscore += teamtable[*j][*k];
				linkscore += teamtable[*k][*j];
			}
		}

		int diff = abs(startscore - linkscore);
		if (diff < ans) ans = diff;
	}

	cout << ans;

	return 0;
}