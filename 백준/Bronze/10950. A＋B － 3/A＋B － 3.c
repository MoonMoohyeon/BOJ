#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	int n1, n2;
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &n1, &n2);
		printf("%d\n", n1 + n2);
	}

	return 0;
}