#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, M;
int arr[1001];
int stack[1001];
int SP = 0;

int isFull() {
	if (SP == 1000) return 1;
	return 0;
}

int isEmpty() {
	if (SP == 0) return 1;
	return 0;
}

void push(int val) {
	if (isFull()) return;
	stack[SP++] = val;
}

int top() {
	return stack[SP - 1];
}

void pop() {
	if (isEmpty()) return;
	stack[SP - 1] = 0;
	SP--;
	return;
}

int main(int argc, char** argv) {

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}

	int cur = 1;

	for (int i = 0; i < N; ++i) {
		//printf("arr = %d i = %d cur = %d\n", arr[i], i, cur);
		if (arr[i] == cur) {
			//printf("match im %d\n", cur);
			cur++;
		}
		else if(top() == cur) {
			//printf("match st %d\n", cur);
			cur++;
			i--;
			pop();
		}
		else {
			push(arr[i]);
		}
	}

	while (!isEmpty()) {
		//printf("top : %d\n", top());
		if (top() == cur) {
			cur++;
			pop();
			//printf("pop : %d\n", pop());
		}
		else {
			printf("Sad");
			return 0;
		}
	}
	printf("Nice");

	return 0;
}