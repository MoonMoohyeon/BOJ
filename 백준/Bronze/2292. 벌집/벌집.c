#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	
	int base = 6;
	int temp = 0;

	for (int i = 0; i < num; i++)
	{
		if (i > 0)
		{
			temp = temp + base * i;
		}
		
		if (num <= temp + 1)
		{
			printf("%d", i + 1);
			break;
		}
	}
	
	return 0;
}