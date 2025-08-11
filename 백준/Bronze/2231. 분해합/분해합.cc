#include <iostream>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);
	int sum = 0;

	for (int i = 1; i < num; i++)
	{
		sum = i;
		int j = i;
		while (j != 0)
		{
			sum += (j % 10);
			j = j / 10;
		}

		if (sum == num)
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("0");

	return 0;
}