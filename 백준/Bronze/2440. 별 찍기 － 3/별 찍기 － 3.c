#include <stdio.h>
#include <math.h>
int main(void)
{
	int num;
	scanf("%d", &num);
	for (int i = num; i >=1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}