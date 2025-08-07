#include <stdio.h>

int cnt = 0;

void find(int n)
{
	if (n < 100) cnt++; // 두자리 숫자는 무조건 등차수열
	else
	{
		int o = n % 10; // 문제 조건이 1000 미만이므로 백의 자리만 검사해보면 된다.
		n = n / 10;
		int d = n % 10;
		int h = n / 10;
		if (h == d && d == o) cnt++; // 모두 같은 경우 등차수열(0)
		for (int i = 1; i < 10; i++) // 자릿수의 차이 검사하기
		{
			if (h + i == d && d + i == o) cnt++;
			if (h - i == d && d - i == o) cnt++;
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		find(i);
	}

	printf("%d", cnt);

	return 0;
}