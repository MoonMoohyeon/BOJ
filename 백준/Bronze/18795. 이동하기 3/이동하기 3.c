#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 500000
#define ll long long
int N, M;
ll ans = 0;

int main(int argc, char* argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N + M; ++i) {
			int tmp;
			scanf("%d", &tmp);
			ans += tmp;
	}

	printf("%lld", ans);

	return 0;
}
