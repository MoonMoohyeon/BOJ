#include <stdio.h>

int main(void)
{
	int cute;
	int num;
	int o = 0;
	int n = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &cute);
		if (!cute)
		{
			n++;
		}
		else if (cute == 1)
		{
			o++;
		}
		else
		{
			continue;
		}
	}

	if (n > o)
	{
		printf("Junhee is not cute!");
	}
	else if (o > n)
	{
		printf("Junhee is cute!");
	}

	return 0;
}