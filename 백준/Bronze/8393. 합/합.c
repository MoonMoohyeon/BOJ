#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int sum = num * (1+num) / 2;

	printf("%d", sum);
	

	return 0;
}