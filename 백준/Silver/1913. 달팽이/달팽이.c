#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, M;
int arr[1000][1000];
int ty, tx;

void printboard() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", arr[i][j]);
			if (arr[i][j] == M) {
				ty = i;
				tx = j;
			}
		}
		printf("\n");
	}
}

void build() {
	int start = N * N;
	int center = N / 2;
	int i = 0, j = 0;
	int left = 0;
	int right = N - 1;
	int bottom = 0;
	int top = N - 1;

	while (i != N / 2 && j != N / 2) {
		for (i = bottom; i <= top; ++i) {
			arr[i][left] = start--;
		}
		bottom++;

		left++;
		for (j = left; j <= right; ++j) {
			arr[i - 1][j] = start--;
		}

		top--;
		for (i = top; i >= bottom; --i) {
			arr[i][right] = start--;
		}

		for (j = right; j >= left; --j) {
			arr[i][j] = start--;
		}
		right--;
	}
}

int main(int argc, char** argv) {

	scanf("%d %d", &N, &M);
	
	build();
	printboard();
	printf("%d %d", ty + 1, tx + 1);


	return 0;
}