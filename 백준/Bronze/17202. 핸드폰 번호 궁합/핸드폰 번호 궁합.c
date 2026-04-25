#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char sum[17];
	char num1[9];
	char num2[9];

	scanf("%s", num1);
	scanf("%s", num2);


	int j = 0;
	for (int i = 0; i < 17; i+=2)
	{
		sum[i] = num1[j];
		sum[i+1] = num2[j++];
	}

	//printf("%s\n", sum);

	for (int j = 15; j >= 2; j--)
	{
		int t = 0;
		for (int i = 0; i < j; i++)
		{
			//printf("\nlen = %d ", strlen(sum));
			int temp = sum[t] - '0' + sum[t + 1] - '0';
			if (temp >= 10) temp -= 10;
			//printf("%d", temp);
			char temp2 = (char)(temp + '0');
			sum[t++] = temp2;
		}
		sum[t] = '\0';
	}
	

	printf("%s", sum);
	

	return 0;
}