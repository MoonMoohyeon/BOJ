#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int array[num];

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}

	int min;	 
	int i, j;
	int index;

	for (i = 0; i < num; i++)
	{
		min = 1001;

		for (j = i; j < num; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
			}
		}

		int temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d\n", array[i]);
	}

	
	return 0;
}