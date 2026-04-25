#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int score[1001];
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &score[i]);
		if (score[i] > max) max = score[i];
	}

	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (double)score[i] / max * 100;
	}

	sum = sum / N;
	printf("%f", sum);

	
	return 0;
}

