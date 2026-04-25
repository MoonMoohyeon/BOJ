#include <stdio.h>
#include <math.h>

int main(void)
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int min1, min2;

	if (abs(x - 0) <= abs(x - w))
	{
		min1 = abs(x - 0);
	}
	else
	{
		min1 = abs(x - w);
	}

	if (abs(y - 0) <= abs(y - h))
	{
		min2 = abs(y - 0);
	}
	else
	{
		min2 = abs(y - h);
	}

	if (min1 <= min2)
	{
		printf("%d", min1);
	}
	else
	{
		printf("%d", min2);
	}

	return 0;
}