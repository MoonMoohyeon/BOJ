#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include <string>
using namespace std;

typedef long long ll;
int N, M;
int DAT[20000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		DAT[input + 10000000] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		if (DAT[input + 10000000]) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}