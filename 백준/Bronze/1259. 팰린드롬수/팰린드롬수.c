#include <stdio.h>

int main(void)
{
	int num;
	int arr[5] = {0, };
	while (1)
	{
		scanf("%d", &num);

		if (!num) break;
		int temp = num;
		int i = 0;
		int sum = 0;
		
		while (temp != 0)
		{
			sum = sum * 10 + temp % 10;
			temp /= 10;
			i++;
		}

		if (sum == num)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	

	return 0;
}