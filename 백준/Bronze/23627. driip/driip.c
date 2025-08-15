#include <stdio.h>
#include <string.h>

int main(void)
{
	char c[1001];
	scanf("%s", c);

	if (c[strlen(c) - 1] == 'p' &&
		c[strlen(c) - 2] == 'i' &&
		c[strlen(c) - 3] == 'i' &&
		c[strlen(c) - 4] == 'r' &&
		c[strlen(c) - 5] == 'd')
	{
		printf("cute");
	}
	else
	{
		printf("not cute");
	}
	
	return 0;
}