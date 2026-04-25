#include <stdio.h>
#include <math.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		printf("Case #%d: %d\n", i + 1, x + y);
	}

	return 0;
}