#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

int N, M;
//int arr[100000];
//int queue[200000];
//int head = 0, tail = 0;
//
//int isFull() {
//	if ((head + 1) % N == tail) return 1;
//	return 0;
//}
//
//int isEmpty() {
//	if (head == tail) return 1;
//	return 0;
//}
//
//void enqueue(int val) {
//	if (isFull()) {
//		return;
//	}
//	queue[head] = val;
//	head = (head + 1) % N;
//}
//
//int dequeue() {
//	if (isEmpty()) {
//		return -1;
//	}
//	int ret = queue[tail];
//	tail = (tail + 1) % N;
//	return ret;
//}
//
//void printq() {
//	printf("q %d, %d : ", tail, head);
//	for (int i = 0; i < N; ++i) {
//		printf("%d ", queue[i]);
//	}
//	printf("\n");
//}

int main(int argc, char** argv) {

	scanf("%d", &N);
	std::queue<int> q;
	while (1) {
		int input;
		scanf("%d", &input);
		if (input == -1) {
			break;
		}
		else if (input == 0) {
			if (!q.empty()) {
				q.pop();
			}
			//dequeue();
			//printq();
		}
		else {
			if (q.size() < N) {
				q.push(input);
			}
			//enqueue(input);
			//printq();
		}
	}

	if (q.empty()) {
		printf("empty");
		return 0;
	}

	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	return 0;
}