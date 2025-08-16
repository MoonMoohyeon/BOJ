#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include <string>
using namespace std;
typedef long long ll;

int N, M;
int graph[101][101] = { 0, };
const int INF = 10e8;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || graph[i][j]) continue;
			graph[i][j] = INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int ans = 0;
	int minv = INF;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			//if (graph[i][j] == INF) cout << "*";
			//else cout << graph[i][j];
			if (graph[i][j] != INF) {
				sum += graph[i][j];
			}
		}
		if (sum < minv) {
			minv = sum;
			ans = i;
		}
		//cout << endl;
	}

	cout << ans;

	return 0;
}