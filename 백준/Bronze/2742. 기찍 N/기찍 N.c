#include <stdio.h>

int main(void)
{
	int num;
	int i;
	scanf("%d", &num);
	for (i = num; i > 0; i--)
	{
		printf("%d\n", num);
		num--;
	}
	return 0;
}