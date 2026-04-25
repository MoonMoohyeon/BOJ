#include <iostream>

int main(void)
{
	int N;
	int min= 1000001, max= -1000001;
	int temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}

	printf("%d %d", min, max);

	return 0;
}

