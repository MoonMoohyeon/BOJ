#include <stdio.h>
#include <string.h>

int main(void)
{
	char array[51];
	int num;
	int lc = 0;
	int rc = 0;
	scanf("%d", &num);

	for (int i = 0; i <= num; i++)
	{
		lc = 0;
		rc = 0;
		for (int j = 0; j < 51; j++)
		{
			scanf("%c", &array[j]);
			if (array[j] == '\n') break;

			if (array[j] == '(')
			{
				lc++;
			}
			else if(array[j] == ')')
			{
				rc++;
			}

			if (rc > lc)
			{
				while (getchar() != '\n');
				break;
			}
		}

		if (i != 0)
		{
			if (lc == rc)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}

	return 0;
}