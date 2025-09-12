#include <stdio.h>
#include <stdlib.h>

int N, K, A, B;
int arr[101];
int cnt = 0;

void firstday() {
	for (int i = 0; i < N; ++i) {
		arr[i] = K;
	}
}

void watering() {
	// 가장 작은 식물을 포함하면서, 범위의 합이 가장 작은 곳에 물을 주기

	int minv = 10e8;
	int minidx = 0;
	for (int i = 0; i < N; ++i) {
		if (arr[i] < minv) {
			minv = arr[i];
			minidx = i;
		}
	}

	// 해당 인덱스부터 A개의 화분에 물 주기
	if (minidx + A >= N) {
		minidx -= (minidx + A - N); // 초과하면 범위 조정하기
	}
	for (int i = minidx; i < minidx + A; ++i) {
		if (i < N) {
			arr[i] += B;
		}
	}
}

void dec() {
	cnt++;
	for (int i = 0; i < N; ++i) {
		arr[i]--;
	}
}

int check() {
	for (int i = 0; i < N; ++i) {
		if (arr[i] == 0) return 1;
	}
	return 0;
}

int main(int argc, char** argv) {

	scanf("%d %d %d %d", &N, &K, &A, &B);
	firstday();

	while (1) {
		//for (int i = 0; i < N; ++i) {
		//	printf("%d ", arr[i]);
		//}
		//printf("\n");
		watering();
		dec();
		if (check()) {
			printf("%d", cnt);
			return 0;
		}
	}
	
	return 0;
}
