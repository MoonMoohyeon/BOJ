#include <stdio.h>
#include <string.h>

int main(void)
{
	char c[101];
	scanf("%s", c);
	int count = 0;
	int j = 0;
	int i = 0;
	while (1)
	{
		if(count >= strlen(c))
			break;

		if (i >= 10)
		{
			printf("\n");
			i = 0;
		}

		printf("%c", c[j]);
		j++;
		count++;
		i++;
	}

	
	return 0;
}