#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int temp;
	int count = 0;

	for (int i = 0; i < num; i++)
	{
		scanf(" %d", &temp);
		if (temp == 1) continue;
		if (temp == 2)
		{
			count++;
			continue;
		}
		int n = 0;
		for (int j = 2; j < temp; j++)
		{
			if (temp % j == 0) n++;
		}
		if (!n)
		{
			count++;
		}
	}
	printf("%d", count);

	return 0;
}