#include <stdio.h>
#include <string.h>

int main(void)
{
	int num;
	int rp;
	char c[21];
	scanf("%d", &num);

	for(int i=0; i<num; i++)
	{
		scanf("%d %s", &rp, c);
		for (int j = 0; j < strlen(c); j++)
		{
			for (int k = 0; k < rp; k++)
			{
				printf("%c", c[j]);
			}
		}
		printf("\n");
	}

	return 0;
}