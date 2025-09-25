#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N;
int arr[200001];

int main(int argc, char* argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}

	int start = N - 1;
	int ans = 0;
	int base = arr[start];
	for (int i = start - 1; i >= 0; --i) {
		if (arr[i] > base) {
			base = arr[i];
			continue;
		}
		int tmp = base - arr[i];
		if (tmp > 0 && tmp > ans) {
			//printf("%d %d %d %d\n", base, arr[i], base - i, ans);
			ans = tmp;
		}
	}

	printf("%d", ans);

	return 0;
}
