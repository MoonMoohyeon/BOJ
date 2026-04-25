#include <stdio.h>
#include <string.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int count = 0;
	while (1)
	{
		if (!(num % 5))
		{
			count++;
			num = num - 5;
		}
		else
		{
			count++;
			num = num - 3;
		}
		if (num < 2)
		{
			break;
		}
	}

	if (!num)
		printf("%d", count);
	else
		printf("-1");
	
	return 0;
}