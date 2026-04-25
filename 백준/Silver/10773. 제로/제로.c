#include <stdio.h>
#include <string.h>

int main(void)
{
	int SP = 0;
	int max;
	scanf("%d", &max);

	int stack[max];
	int n;
	int count = 0;

	for (int i = 0; i < max; i++)
	{
		stack[i] = 0;
	}

	for (int i = 0; i < max; i++)
	{
		scanf("%d", &n);
		if (n != 0)
		{
			stack[SP++] = n;
			count++;
		}
			
		else if(n == 0)
			stack[--SP] = 0;
	}

	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += stack[i];
	}
	printf("%d", sum);

	return 0;
}