#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int x, y;
	int min = 100001, max = -1;

	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &x, &y);
		if (x > max) max = x;
		if (y < min) min = y;
	}

	if (max - min < 0) printf("0");
	else printf("%d", max - min);

	return 0;
}