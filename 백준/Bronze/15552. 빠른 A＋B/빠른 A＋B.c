#include <stdio.h>

int main(void)
{
	int max;
	int a, b;
	scanf("%d", &max);
	for (int i = max; i >= 1; i--)
	{
		scanf(" %d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}