#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define ll long long

int T, Q;

int minheap[1000001];
int maxheap[1000001];
int minheap2[1000001];
int maxheap2[1000001];

int minSize = 0;
int maxSize = 0;
int minSize2 = 0;
int maxSize2 = 0;

int isMinEmpty(int which) {
	if (which == 1) {
		if (minSize == 0) {
			return 1;
		}
	}
	else {
		if (minSize2 == 0) {
			return 1;
		}
	}

	return 0;
}

int isMaxEmpty(int which) {
	if (which == 1) {
		if (maxSize == 0) {
			return 1;
		}
	}
	else {
		if (maxSize2 == 0) {
			return 1;
		}
	}

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minPush(int val, int which) {
	/*
		배열에 맨 마지막 공간에 넣고(size)
		부모 노드와 비교하면서 올려보낸다.
	*/

	if (which == 1) {
		minheap[++minSize] = val;
		int cur = minSize;
		int parent = cur / 2;
		while (parent > 0 && minheap[cur] < minheap[parent]) {
			swap(&minheap[cur], &minheap[parent]);
			cur = parent;
			parent = cur / 2;
		}
	}
	else {
		minheap2[++minSize2] = val;
		int cur = minSize2;
		int parent = cur / 2;
		while (parent > 0 && minheap2[cur] < minheap2[parent]) {
			swap(&minheap2[cur], &minheap2[parent]);
			cur = parent;
			parent = cur / 2;
		}
	}
}

void maxPush(int val, int which) {
	if (which == 1) {
		maxheap[++maxSize] = val;
		int cur = maxSize;
		int parent = cur / 2;
		while (parent > 0 && maxheap[cur] > maxheap[parent]) {
			swap(&maxheap[cur], &maxheap[parent]);
			cur = parent;
			parent = cur / 2;
		}
	}
	else {
		maxheap2[++maxSize2] = val;
		int cur = maxSize2;
		int parent = cur / 2;
		while (parent > 0 && maxheap2[cur] > maxheap2[parent]) {
			swap(&maxheap2[cur], &maxheap2[parent]);
			cur = parent;
			parent = cur / 2;
		}
	}
}


void minHeapify(int idx, int which) {
	if (which == 1) {
		int cur = idx;
		int leftChild = idx * 2;
		int rightChild = idx * 2 + 1;

		if (leftChild > minSize) return;

		int minidx = cur;
		if (minheap[cur] > minheap[leftChild]) minidx = leftChild;
		if (rightChild <= minSize && minheap[minidx] > minheap[rightChild]) minidx = rightChild;
		if (minidx == cur) return;
		swap(&minheap[cur], &minheap[minidx]);
		minHeapify(minidx, which);
	}
	else {
		int cur = idx;
		int leftChild = idx * 2;
		int rightChild = idx * 2 + 1;

		if (leftChild > minSize2) return;

		int minidx = cur;
		if (minheap2[cur] > minheap2[leftChild]) minidx = leftChild;
		if (rightChild <= minSize2 && minheap2[minidx] > minheap2[rightChild]) minidx = rightChild;
		if (minidx == cur) return;
		swap(&minheap2[cur], &minheap2[minidx]);
		minHeapify(minidx, which);
	}
}

void maxHeapify(int idx, int which) {
	if (which == 1) {
		int cur = idx;
		int leftChild = idx * 2;
		int rightChild = idx * 2 + 1;

		if (leftChild > maxSize) return;

		int maxidx = cur;
		if (maxheap[cur] < maxheap[leftChild]) maxidx = leftChild;
		if (rightChild <= maxSize && maxheap[maxidx] < maxheap[rightChild]) maxidx = rightChild;
		if (maxidx == cur) return;
		swap(&maxheap[cur], &maxheap[maxidx]);
		maxHeapify(maxidx, which);
	}
	else {
		int cur = idx;
		int leftChild = idx * 2;
		int rightChild = idx * 2 + 1;

		if (leftChild > maxSize2) return;

		int maxidx = cur;
		if (maxheap2[cur] < maxheap2[leftChild]) maxidx = leftChild;
		if (rightChild <= maxSize2 && maxheap2[maxidx] < maxheap2[rightChild]) maxidx = rightChild;
		if (maxidx == cur) return;
		swap(&maxheap2[cur], &maxheap2[maxidx]);
		maxHeapify(maxidx, which);
	}
}

int minTop(int which) {
	if (which == 1) {
		return minheap[1];
	}
	else {
		return minheap2[1];
	}
}

int maxTop(int which) {
	if (which == 1) {
		return maxheap[1];
	}
	else {
		return maxheap2[1];
	}
}

int minPop(int which) {
	/*
		루트 노드를 반환하고, 맨 마지막 노드를 루트로 올린다.
		루트로 올라온 노드를 자식 노드와 비교하면서 내려보낸다.
		두 자식 노드와 비교하여 더 작은 쪽으로 내려야 한다.
	*/

	if (which == 1) {
		if (isMinEmpty(which)) {
			return -10e8;
		}

		int top = minheap[1];
		int last = minheap[minSize];
		minheap[minSize--] = 0;
		minheap[1] = last;
		minHeapify(1, which);

		return top;
	}
	else {
		if (isMinEmpty(which)) {
			return -10e8;
		}

		int top = minheap2[1];
		int last = minheap2[minSize2];
		minheap2[minSize2--] = 0;
		minheap2[1] = last;
		minHeapify(1, which);

		return top;
	}
}

int maxPop(int which) {

	if (which == 1) {
		if (isMaxEmpty(which)) {
			return -10e8;
		}

		int top = maxheap[1];
		int last = maxheap[maxSize];
		maxheap[maxSize--] = 0;
		maxheap[1] = last;
		maxHeapify(1, which);

		return top;
	}
	else {
		if (isMaxEmpty(which)) {
			return -10e8;
		}

		int top = maxheap2[1];
		int last = maxheap2[maxSize2];
		maxheap2[maxSize2--] = 0;
		maxheap2[1] = last;
		maxHeapify(1, which);

		return top;
	}
}

int main(int argc, char** argv) {

	memset(minheap, 0, sizeof(minheap));
	memset(maxheap, 0, sizeof(maxheap));
	memset(minheap2, 0, sizeof(minheap2));
	memset(maxheap2, 0, sizeof(maxheap2));

	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {

		minSize = 0;
		maxSize = 0;
		minSize2 = 0;
		maxSize2 = 0;

		scanf("%d", &Q);
		for (int q = 0; q < Q; ++q) {
			char cmd;
			int num;
			scanf(" %c %d", &cmd, &num);

			if (cmd == 'I') {
				minPush(num, 1);
				maxPush(num, 1);
			}
			else if (cmd == 'D') {
				if (num == -1) {
					while (!isMinEmpty(1) && !isMinEmpty(2) && minTop(1) == minTop(2)) {
						minPop(1);
						minPop(2);
					}
					if (!isMinEmpty(1)) {
						int deleted_val = minPop(1);
						maxPush(deleted_val, 2);
					}
				}
				else {
					while (!isMaxEmpty(1) && !isMaxEmpty(2) && maxTop(1) == maxTop(2)) {
						maxPop(1);
						maxPop(2);
					}
					if (!isMaxEmpty(1)) {
						int deleted_val = maxPop(1);
						minPush(deleted_val, 2);
					}
				}
			}
		}

		while (!isMaxEmpty(1) && !isMaxEmpty(2) && maxTop(1) == maxTop(2)) {
			maxPop(1);
			maxPop(2);
		}
		while (!isMinEmpty(1) && !isMinEmpty(2) && minTop(1) == minTop(2)) {
			minPop(1);
			minPop(2);
		}

		//printf("top : %d %d %d %d, size : %d %d %d %d\n", minTop(1), minTop(2), maxTop(1), maxTop(2), minSize, minSize2, maxSize, maxSize2);

		if (isMinEmpty(1)) {
			printf("EMPTY\n");
		}
		else {
			printf("%d %d\n", maxTop(1), minTop(1));
		}
	}
	return 0;
}