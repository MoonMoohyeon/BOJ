#include <stdio.h>

int main(void)
{
	int num1, num2, num3;

	while (1)
	{
		scanf("%d %d %d", &num1, &num2, &num3);

		if (num1 == 0 && num2 == 0 && num3 == 0)
			break;

		int l;
		if (num1 > num2)
		{
			if (num1 > num3)
			{
				l = num1;
			}
			else
			{
				l = num3;
			}
		}
		else
		{
			if (num2 > num3)
			{
				l = num2;
			}
			else
			{
				l = num3;
			}
		}

		if (num1 == l)
		{
			if (l * l == num2 * num2 + num3 * num3)
				printf("right\n");
			else
				printf("wrong\n");
		}

		if (num2 == l)
		{
			if (l * l == num1 * num1 + num3 * num3)
				printf("right\n");
			else
				printf("wrong\n");
		}

		if (num3 == l)
		{
			if (l * l == num2 * num2 + num1 * num1)
				printf("right\n");
			else
				printf("wrong\n");
		}
	}
	

	return 0;
}