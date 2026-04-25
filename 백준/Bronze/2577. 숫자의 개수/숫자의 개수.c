#include <stdio.h>
#include <string.h>

int main(void)
{
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);
	int r = num1 * num2 * num3;

	int array[10] = {0, };

	while (r != 0)
	{
		int temp = r % 10;
		array[temp]++;
		r = r / 10;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", array[i]);
	}


	return 0;
}