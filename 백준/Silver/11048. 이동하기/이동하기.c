#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, M;
int map[1001][1001];
int DP[1001][1001];

int main(int argc, char** argv) {

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &map[i][j]);
			DP[i][j] = map[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			int maxv = 0;
			int v1 = DP[i - 1][j];
			int v2 = DP[i][j - 1];
			int v3 = DP[i - 1][j - 1];
			if (v1 >= v2 && v1 >= v3) {
				maxv = v1;
			}
			if (v2 >= v1 && v2 >= v3) {
				maxv = v2;
			}
			if (v3 >= v1 && v3 >= v2) {
				maxv = v3;
			}

			DP[i][j] += maxv;
		}
	}

	printf("%d", DP[N][M]);

	return 0;
}