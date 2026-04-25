#include <stdio.h>
#include <string.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int count = 0;
	while (1)
	{
		if (num >= 5 && (num % 5) % 2 == 0)
		{
			count++;
			num -= 5;
		}
		else if (num >= 2)
		{
			count++;
			num -= 2;
		}

		if (num == 0)
		{
			printf("%d", count);
			break;
		}
		else if(num == 1)
		{
			printf("-1");
			break;
		}
	}


	return 0;
}