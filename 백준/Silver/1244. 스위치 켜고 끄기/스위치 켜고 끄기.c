#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, M;
int sw[101];

void change(int pos) {
	if (sw[pos] == 0) sw[pos] = 1;
	else if (sw[pos] == 1) sw[pos] = 0;
}

void male(int pos) {
	for (int i = 1; i <= N; ++i) {
		if (i % pos == 0) {
			change(i);
		}
	}
}

void female(int pos) {
	change(pos);

	int lptr = pos - 1;
	int rptr = pos + 1;
	while (sw[lptr] == sw[rptr]) {
		if (lptr <= 0 || rptr > N) break;
		change(lptr);
		change(rptr);
		lptr--;
		rptr++;
	}
}

void printsw() {
	for (int i = 1; i <= N; ++i) {
		printf("%d ", sw[i]);
		if (i % 20 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

int main(int argc, char** argv) {

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &sw[i]);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int gen, pos;
		scanf("%d %d", &gen, &pos);
		if (gen == 1) {
			male(pos);
			//printsw();
		}
		else if (gen == 2) {
			female(pos);
			//printsw();
		}
	}

	printsw();

	return 0;
}