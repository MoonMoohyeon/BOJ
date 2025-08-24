#include <stdio.h>
#include <stdlib.h>

int arr[10001];

int main()
{
	int n;
	scanf("%d", &n);

	/*
		카운팅 정렬
		정렬하려는 수의 범위가 작고, 정렬하려는 수의 개수가 많은 경우
		각 수를 배열 한 칸에 대응시켜 개수를 저장한다.
	*/
	
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (arr[i]--) {
			printf("%d\n", i);
		}
	}

	return 0;
}