#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int temp = num;
	while (1)
	{
		if (num > 1)
		{
			printf("%d bottles of beer on the wall, %d bottles of beer.\n", num, num);
			if (num - 1 == 1)
			{
				printf("Take one down and pass it around, %d bottle of beer on the wall.\n\n", num - 1);
			}
			else
				printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", num - 1);
			num--;
		}
		else if (num == 1)
		{
			printf("%d bottle of beer on the wall, %d bottle of beer.\n", num, num);
			printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
			num--;
		}
		else if (temp == 1)
		{
			printf("No more bottles of beer on the wall, no more bottles of beer.\n");
			printf("Go to the store and buy some more, %d bottle of beer on the wall.", temp);
			break;
		}
		else if (num == 0)
		{
			printf("No more bottles of beer on the wall, no more bottles of beer.\n");
			printf("Go to the store and buy some more, %d bottles of beer on the wall.", temp);
			break;
		}
	}

	return 0;
}