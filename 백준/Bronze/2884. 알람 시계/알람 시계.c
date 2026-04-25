#include <stdio.h>

int main(void)
{
	int h, m;
	scanf("%d %d", &h, &m);
	if (m >= 45)
	{
		m -= 45;
	}
	else
	{
		m = m + 60 - 45;
		if (h > 0)
		{
			h -= 1;
		}
		else
		{
			h = 23;
		}
		
	}
	printf("%d %d", h, m);

	return 0;
}