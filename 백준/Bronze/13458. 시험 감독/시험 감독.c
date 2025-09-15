#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define ll long long

int N, B, C;
int arr[1000001];

int main(int argc, char** argv) {

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);

	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		int temp = arr[i] - B;
		ans++;
		if (temp > 0) {
			if (temp % C != 0) {
				ans++;
			}
			ans += temp /= C;
		}
	}

	printf("%lld", ans);

	return 0;
}
