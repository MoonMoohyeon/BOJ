#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define ll long long

int N;
int home[200001];
int leftarr[100001];
int rightarr[100001];

void merge(int* arr, int start, int end) {

	int size = end - start + 1;
	int mid = (end + start) / 2;

	memcpy(leftarr, arr, sizeof(int) * (size - size / 2));
	memcpy(rightarr, arr + size - (size / 2), sizeof(int) * size / 2);
	
	int leftptr, rightptr;
	leftptr = rightptr = 0; // 합칠 배열의 포인터들
	int idx = 0; // 합치는 배열의 포인터

	while (leftptr != (size - size / 2) && rightptr != size / 2) {
		if (leftarr[leftptr] < rightarr[rightptr]) {
			arr[idx++] = leftarr[leftptr++];
		}
		else {
			arr[idx++] = rightarr[rightptr++];
		}
	}

	while (leftptr != (size - size / 2)) {
		arr[idx++] = leftarr[leftptr++];
	}

	while (rightptr != size / 2) {
		arr[idx++] = rightarr[rightptr++];
	}
}

void merge_sort(int* arr, int start, int end) {

	if (start == end) return;

	int size = end - start + 1;
	int mid = (end + start) / 2;
	
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr + start, start, end);
}

void printarr() {
	for (int i = 0; i < N; ++i) {
		printf("%d ", home[i]);
	}
	printf("\n");
}

ll calcost(int point) {
	ll res = 0;
	for (int i = 0; i < N; ++i) {
		res += abs(home[point] - home[i]);
		//printf("%d %d res += %d\n", home[point], home[i], abs(home[point] - home[i]));
	}
	//printf("\n");
	
	return res;
}

int main(int argc, char** argv) {

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &home[i]);
	}

	merge_sort(home, 0, N - 1);
	
	int point = N / 2;
	ll dist = calcost(point);
	ll ans = point;
	ll res = dist;
	while (point < N) {
		if(point < N) dist = calcost(point);
		//printf("dist = %d ans = %d point = %d home = %d\n", dist, ans, point, home[point]);
		if (dist < res) {
			res = dist;
			ans = point;
		}
		else {
			break;
		}

		point++;
	}

	point = N / 2;
	while (point >= 0) {
		if (point >= 0) dist = calcost(point);
		//printf("dist = %d ans = %d point = %d home = %d\n", dist, ans, point, home[point]);
		if (dist <= res) {
			res = dist;
			ans = point;
		}
		else {
			break;
		}
		
		point--;
	}

	printf("%d", home[ans]);


	return 0;
}
