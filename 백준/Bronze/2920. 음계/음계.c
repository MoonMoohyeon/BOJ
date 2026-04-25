#include <stdio.h>

int main(void)
{
	int array[8];
	int check = 0;
	int check2 = 0;
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		if (array[i] == array[i+1] - 1)
		{
			check++;
		}
		else if(array[i] == array[i+1] + 1)
		{
			check2++;
		}
	}
	if (check == 7)
	{
		printf("ascending");
	}
	else if (check2 == 7)
	{
		printf("descending");
	}
	else
	{
		printf("mixed");
	}

	return 0;
}