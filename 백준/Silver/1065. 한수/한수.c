#include <stdio.h>

int cnt = 0;

void find(int n)
{
	if (n < 100) cnt++;
	else
	{
		int o = n % 10;
		n = n / 10;
		int d = n % 10;
		int h = n / 10;
		if (h == d && d == o) cnt++;
		for (int i = 1; i < 10; i++)
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