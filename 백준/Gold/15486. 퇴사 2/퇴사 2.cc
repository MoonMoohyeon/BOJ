#include <iostream>
#include <algorithm>
using namespace std;

int T[1500001];
int P[1500001];
int DP[1500002];

int main(void) {

	// DP[i] = i번째 날까지의 최대 이익
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)  {
		scanf("%d %d", &T[i], &P[i]);
	}

	for (int i = 1; i <= N; i++) {
		// 오늘 상담을 안 하고 다음 날로 넘어가는 경우
		DP[i + 1] = max(DP[i + 1], DP[i]);

		// 오늘 상담을 해서 미래의 수익을 갱신하는 경우
		if (i + T[i] <= N + 1) {
			DP[i + T[i]] = max(DP[i + T[i]], DP[i] + P[i]);
		}
	}
	printf("%d", DP[N + 1]);

	return 0;
}