#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1001];
int DP[1001];

int main(int argc, char** argv) {
	int T, N;
	scanf("%d", &T);

	for (int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		int maxv = -10e8;
		int flag = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
			if (arr[i] > maxv) maxv = arr[i];
			if (arr[i] > 0) flag = 1;
		}

		DP[0] = arr[0];
		if (arr[0] < 0) DP[0] = 0;
		for (int i = 1; i < N; ++i) {
			int v1 = DP[i - 1] + arr[i];
			int v2 = arr[i];
			if (v1 >= v2) {
				DP[i] = v1;
			}
			else if (v2 >= v1) {
				DP[i] = v2;
			}
		}

		if (!flag) {
			printf("%d\n", maxv);
			continue;
		}
		
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			if (DP[i] > ans) ans = DP[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}